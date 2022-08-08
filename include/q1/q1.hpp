#include <string>
#include <vector>

#ifndef Q1_HPP
#define Q1_HPP

namespace q1 {

auto run_calculator(std::vector<std::string> const& input) -> std::vector<std::string> const;
auto split(const std::string& s) -> std::vector<std::string>;
auto  div(const std::vector<std::string>& v) -> std::string;
auto  mult(const std::vector<std::string>& v) -> std::string;
auto  add(const std::vector<std::string>& v) -> std::string;
auto  sub(const std::vector<std::string>& v) -> std::string;
auto  sqrt(const std::vector<std::string>& v) -> std::string;
auto  reverse(const std::vector<std::string>& v);

} // namespace q1

#endif // Q1_HPP
