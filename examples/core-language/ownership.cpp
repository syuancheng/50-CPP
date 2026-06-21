#include <cassert>
#include <memory>
#include <string>
#include <utility>

class Session {
public:
    explicit Session(std::string name) : name_(std::move(name)) {}
    const std::string& name() const noexcept { return name_; }

private:
    std::string name_;
};

std::unique_ptr<Session> make_session(std::string name) {
    return std::make_unique<Session>(std::move(name));
}

std::size_t observed_name_size(const Session& session) {
    return session.name().size();
}

int main() {
    auto owner = make_session("primary");
    assert(observed_name_size(*owner) == 7);

    auto new_owner = std::move(owner);
    assert(!owner);
    assert(new_owner->name() == "primary");
}
