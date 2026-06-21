//
// Created by Siyuan Cheng on 2022/4/24.
//

#ifndef INC_50_CPP_STACH_H
#define INC_50_CPP_STACH_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cstddef>
#include <utility>

class Stack {
public:
    bool push( const std::string& );
    bool pop( std::string &elem);
    bool peek(std::string &elem);

    bool find( const std::string &elem) const;
    std::size_t count( const std::string &elem) const;

    bool empty() const { return _stack.empty(); }
    bool full() const { return _stack.size() == _stack.max_size(); }
    std::size_t size() const { return _stack.size(); }

private:
    std::vector<std::string> _stack;
};

inline bool Stack::peek(std::string &elem) {
    if (empty()){
        return false;
    }
    elem = _stack.back();
    return true;
}

inline bool Stack::push(const std::string &elem) {
    if (full()) {
        return false;
    }
    _stack.push_back(elem);
    return true;
}

inline bool Stack::pop(std::string &elem) {
    if (empty()){
        return false;
    }

    elem = _stack.back();
    _stack.pop_back();

    return true;
}

inline bool Stack::find(const std::string &elem) const {
    std::vector<std::string>::const_iterator end_it = _stack.end();
    return std::find(_stack.begin(), _stack.end(), elem) != end_it;
}

inline std::size_t Stack::count(const std::string &elem) const {
    return std::count(_stack.begin(), _stack.end(), elem);
}



//Exercise 4.3
class globalWrapper {
public:
    static int tests_passed() { return _tests_passed; }
    static int tests_run() {return _tests_run;}
    static int version_number() {return _version_number;}
    static std::string version_stamp() { return _version_stamp;}
    static std::string program_name() {return _program_name;}

    static void tests_passed(int nval) { _tests_passed = nval;}
    static void tests_run(int nval) { _tests_run = nval; }
    static void version_number(int nval) {_version_number = nval;}

    static void version_stamp(const std::string & nstamp){
        _version_stamp = nstamp;
    }
    static void program_name(const std::string& npn){
        _program_name = npn;
    }

private:
    static std::string _program_name;
    static std::string _version_stamp;
    static int    _version_number;
    static int    _tests_run;
    static int    _tests_passed;
};

inline std::string globalWrapper::_program_name;
inline std::string globalWrapper::_version_stamp;
inline int globalWrapper::_version_number;
inline int globalWrapper::_tests_run;
inline int globalWrapper::_tests_passed;

//Exercise 4.4
class UserProfile {
public:
    enum uLevel {Beginner, Intermediate, Advanced, Guru};

    UserProfile(std::string login, uLevel = Beginner);
    UserProfile();

    bool operator==(const UserProfile& );
    bool operator!=(const UserProfile &rhs);

    //read
    std::string login() const { return _login; }
    std::string user_name() const { return _user_name; }
    int login_count() const { return _times_logged; }
    int guess_count() const { return _guesses; }
    int guess_correct() const { return _correct_guesses; }
    double guess_average() const;
    std::string level() const;

    //write
    void reset_login(const std::string& val){ _login = val; }
    void user_name(const std::string& val){ _user_name = val; }

    void reset_level(const std::string& );
    void reset_level(uLevel newlevel ){ _user_level = newlevel; }

    void reset_login_count( int val ){ _times_logged = val; }
    void reset_guess_count( int val ){ _guesses = val; }
    void reset_guess_correct( int val ){ _correct_guesses = val; }

    void bump_login_count( int cnt=1 ){ _times_logged += cnt; }
    void bump_guess_count( int cnt=1 ){ _guesses += cnt; }
    void bump_guess_correct(int cnt=1){ _correct_guesses += cnt;}


private:
    static std::string guest_login();

    std::string _login;
    std::string _user_name;
    int    _times_logged;
    int _guesses;
    int _correct_guesses;
    uLevel _user_level;

    static std::map<std::string, uLevel> _level_map;
    static void init_level_map();
};

inline UserProfile::UserProfile(std::string login, uLevel level)
    : _login(std::move(login)), _times_logged(1), _guesses(0),
      _correct_guesses(0), _user_level(level)
{}

inline UserProfile::UserProfile()
    : _login("guest"), _times_logged(1), _guesses(0),
      _correct_guesses(0), _user_level(Beginner)
{
    static int id = 0;
    _login += std::to_string(id++);
}

inline bool UserProfile::
operator==( const UserProfile &rhs ){
    if (_login == rhs._login && _user_name == rhs._user_name){
        return true;
    }
    return false;
}

inline bool UserProfile::
operator!=(const UserProfile &rhs) {
    return (!(*this == rhs));
}

inline std::ostream& operator<<( std::ostream &os, const UserProfile &rhs )
{ /* output of the form:
   * stanl Beginner 12 100 10 10%
   **/
    os << rhs.login() << ' '
       << rhs.level() << ' '
       << rhs.login_count() << ' '
       << rhs.guess_count() << ' '
       << rhs.guess_correct() << ' '
       << rhs.guess_average() << std::endl;
    return os;
}

inline double UserProfile::guess_average() const {
    return _guesses ? double(_correct_guesses) / double(_guesses) * 100 : 0.0;
}

inline void UserProfile::init_level_map() {
    _level_map["Beginner"] = Beginner;
    _level_map["Intermediate"] = Intermediate;
    _level_map["Advanced"] = Advanced;
    _level_map["Guru"] = Guru;
}

inline std::string UserProfile::level() const {
    static std::string _level_table[] = {
            "Beginner", "Intermediate", "Advanced", "Guru"
    };

    return _level_table[_user_level];
}

inline void UserProfile::reset_level(const std::string &level) {
    if (_level_map.empty()){
        init_level_map();
    }
    auto iter = _level_map.find(level);
    if (iter == _level_map.end()){
        _user_level = Beginner;
        return;
    }
    _user_level = iter->second;
}

inline std::map<std::string, UserProfile::uLevel> UserProfile::_level_map;

#endif //INC_50_CPP_STACH_H
