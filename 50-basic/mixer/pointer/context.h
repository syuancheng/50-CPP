#include "string"
#include "unordered_map"

struct Context {
public:
    virtual ~Context() {};
private:
    Context* bnd_ctx;
    std::unordered_map<std::string, std::shared_ptr<Context>> sec_ctx_map;
public:
    uint64_t uid = 0;
    std::string request_id = "";
    std::string upstream_ip = "";
    std::string ranker_name = "";
    std::string feature_version = "v1";

    inline void add_sec_ctx(const std::string& section_name) {
        if (sec_ctx_map.find(section_name) == sec_ctx_map.end()) {
            sec_ctx_map.emplace(section_name, std::make_shared<Context>());
        }
    }

    inline std::shared_ptr<Context> sec_ctx(const std::string& section_name) {
        if (sec_ctx_map.find(section_name) == sec_ctx_map.end()) {
            sec_ctx_map.emplace(section_name, std::make_shared<Context>());
        }
        return sec_ctx_map[section_name];
    }

    inline void set_bnd_ctx(Context& ctx) {
        bnd_ctx = &ctx;
    }

    inline Context& get_bnd_ctx() {
        return *bnd_ctx;
    }
};