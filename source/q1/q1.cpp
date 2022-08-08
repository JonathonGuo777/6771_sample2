#include <fstream>
#include <iomanip>
#include <iostream>

#include <q1/q1.hpp>

namespace q1 {
    // write a split function that splits a string into a vector of strings, according to " "
    std::vector<std::string> split(const std::string& s) {
        std::vector<std::string> result;
        std::string::size_type i = 0;
        while (i < s.size()) {
            std::string::size_type j = s.find(' ', i);
            if (j == std::string::npos) {
                result.push_back(s.substr(i));
                break;
            } else {
                result.push_back(s.substr(i, j - i));
            }
            i = j + 1;
        }
        return result;
    }

    // write a div function that divides the last two elements of a vector of strings, and returns the result
    std::string div(const std::vector<std::string>& v) {
        if (v.size() < 2) {
            throw std::runtime_error("not enough elements");
        }
        std::stringstream ss;
        auto string_1 = v.pop_back();
        auto string_2 = v.pop_back();
        if (string_1.find"."!= std::string::npos and string_2.find"."!= std::string::npos) {
            auto x = std::stod(string_1);
            auto y = std::stod(string_2);
            ss << std::setprecision(3)<< x<<"/"<< std::setprecision(3)<< y<< "="<< std::setprecision(3)<< x/y;
        } else {
            auto x = std::stoi(string_1);
            auto y = std::stoi(string_2);
            ss <<x <<"/"<<y <<"=" << int(std::stoi(string_1) / std::stoi(string_2));
        }
        return ss.str();
    }
    // write mul function according to the previous div function
    std::string mul(const std::vector<std::string>& v) {
        if (v.size() < 2) {
            throw std::runtime_error("not enough elements");
        }
        std::stringstream ss;
        auto string_1 = v.pop_back();
        auto string_2 = v.pop_back();
        if (string_1.find"."!= std::string::npos and string_2.find"."!= std::string::npos) {
            auto x = std::stod(string_1);
            auto y = std::stod(string_2);
            ss << std::setprecision(3)<< x<<"*"<< std::setprecision(3)<< y<< "="<< std::setprecision(3)<< x*y;
        } else {
            auto x = std::stoi(string_1);
            auto y = std::stoi(string_2);
            ss <<x <<"*"<<y <<"=" << int(std::stoi(string_1) * std::stoi(string_2));
        }
        return ss.str();
    }

    // write an add function according to the previous div function
    std::string add(const std::vector<std::string>& v) {
        if (v.size() < 2) {
            throw std::runtime_error("not enough elements");
        }
        std::stringstream ss;
        auto string_1 = v.pop_back();
        auto string_2 = v.pop_back();
        if (string_1.find"."!= std::string::npos and string_2.find"."!= std::string::npos) {
            auto x = std::stod(string_1);
            auto y = std::stod(string_2);
            ss << std::setprecision(3)<< x<<"+"<< std::setprecision(3)<< y<< "="<< std::setprecision(3)<< x+y;
        } else {
            auto x = std::stoi(string_1);
            auto y = std::stoi(string_2);
            ss <<x <<"+"<<y <<"=" << int(std::stoi(string_1) + std::stoi(string_2));
        }
        return ss.str();
    }

    // write a sub function according to the previous div function
    std::string sub(const std::vector<std::string>& v) {
        if (v.size() < 2) {
            throw std::runtime_error("not enough elements");
        }
        std::stringstream ss;
        auto string_1 = v.pop_back();
        auto string_2 = v.pop_back();
        if (string_1.find"."!= std::string::npos and string_2.find"."!= std::string::npos) {
            auto x = std::stod(string_1);
            auto y = std::stod(string_2);
            ss << std::setprecision(3)<< x<<"-"<< std::setprecision(3)<< y<< "="<< std::setprecision(3)<< x-y;
        } else {
            auto x = std::stoi(string_1);
            auto y = std::stoi(string_2);
            ss <<x <<"-"<<y <<"=" << int(std::stoi(string_1) - std::stoi(string_2));
        }
        return ss.str();
    }

    // write a sqrt function that takes the square root of the last element of a vector of strings, and returns the result
    std::string sqrt(const std::vector<std::string>& v) {
        if (v.size() < 1) {
            throw std::runtime_error("not enough elements");
        }
        std::stringstream ss;
        // string 1 comes from the last element of the vector
        auto string_1 = v.pop_back();
        // if '.' in string_1 or string_2, throw error
        if (string_1.find('.') != std::string::npos) {
            auto x = std::stod(string_1);
            ss << "sqrt"<<x <<"=" <<std::setprecision(3)<<::sqrt(x);
        }
        else {
            auto x = std::stoi(string_1);
            ss << "sqrt"<<x <<"=" <<std::setprecision(3)<<::sqrt(x);
        }
        return ss.str();
    }

    // void function that reverses the last n elements of a vector of strings
    void reverse(std::vector<std::string>& v, int nn) {
        if (v.size() < nn) {
            throw std::runtime_error("not enough elements");
        }
        std::reverse(v.end() - nn, v.end());
    }


    auto run_calculator(std::vector<std::string> const& input) -> std::vector<std::string> const {
        auto virtual_stack = std::vector<std::string>{};
        auto repeat_stack = std::vector<std::string>{};
        auto repeat_count = 0;
        auto repeat_mode = false;
		auto output = std::vector<std::string>{};

        // loop through the input through iterators
        for (auto it = input.begin(); it != input.end(); ++it) {
            // check if the current string is a command
            // if (*it) is not a null string
            if ((*it) != ""){

                auto tokens = split((*it));
                // loop through the tokens
                for (auto token = tokens.begin(); token != tokens.end(); ++token) {
                    if (repeat_mode){
                        // add the current token to the repeat stack
                        repeat_stack.push_back((*token));
                    }
                    // check if the current token is a command
                    else if ((*token) == "sub" || (*token) == "add" || (*token) == "mult" || (*token) == "div"
                                || (*token) == "sqrt" || (*token) == "reverse" || (*token) == "pop"
                                    || (*token) == "repeat" || (*token) == "endrepeat") {
                        // check if the current token is a repeat command
                        if ((*token) == "repeat"){
                            // set the repeat mode to true
                            repeat_mode = true;
                            // set the repeat count according to the previous token
                            repeat_count = std::stoi(virtual_stack.back());
                            // remove the previous token from the virtual stack
                            virtual_stack.pop_back();
                        }
                        else if ((*token) == "endrepeat"){
                            // set the repeat mode to false
                            repeat_mode = false;
                            // loop through the repeat stack
                            for (auto i = 0; i < repeat_count; ++i){
                                // loop through the repeat stack use iterators
                                for (auto it = repeat_stack.begin(); it != repeat_stack.end(); ++it) {
                                    // check if the current token is a command
                                    if ((*it) == "sub" || (*it) == "add" || (*it) == "mult" || (*it) == "div"
                                    || (*it) == "sqrt" || (*it) == "reverse" || (*it) == "pop") {
                                        if ((*it) == "sub") {
                                            // call the sub function
                                            output.push_back(sub(virtual_stack));
                                        }
                                        else if ((*it) == "add") {
                                            // call the add function
                                            output.push_back(add(virtual_stack));
                                        }
                                        else if ((*it) == "mult") {
                                            // call the mult function
                                            output.push_back(mult(virtual_stack));
                                        }
                                        else if ((*it) == "div") {
                                            // call the div function
                                            output.push_back(div(virtual_stack));
                                        }
                                        else if ((*it) == "sqrt") {
                                            // call the sqrt function
                                            output.push_back(sqrt(virtual_stack));
                                        }
                                        else if ((*it) == "reverse") {
                                            // call the reverse function
                                            reverse(virtual_stack, std::stoi(virtual_stack.back()));
                                        }
                                        else if ((*it) == "pop") {
                                            // call the pop function
                                            virtual_stack.pop_back();
                                        }
                                    }
                                }
                                // clear the repeat stack
                                repeat_stack.clear();
                            }
                        }
                        else if ((*token) == "pop"){
                            virtual_stack.pop_back();
                        }
                        else if ((*token) == "reverse"){
                            reverse(virtual_stack, std::stoi(virtual_stack.back()));
                            virtual_stack.pop_back();
                        }
                        else if ((*token) == "sqrt"){
                            output.push_back(sqrt(virtual_stack));
                        }
                        else if ((*token) == "div"){
                            output.push_back(div(virtual_stack));
                        }
                        else if ((*token) == "mult"){
                            output.push_back(mult(virtual_stack));
                        }
                        else if ((*token) == "add"){
                            output.push_back(add(virtual_stack));
                        }
                        else if ((*token) == "sub"){
                            output.push_back(sub(virtual_stack));
                        }
                    }
                    else {
                        // if the current token is not a command, add it to the virtual stack
                        virtual_stack.push_back((*token));
                    }
                }
            }
        }
        return output;
    }
}// namespace q1





/*
                if (it->find(" ") != std::string::npos) {
                    // split the string into tokens

                    // check if the first token is a command
                    if (tokens[0] == "sub") {
                        // get the second element from the stack
                        auto const second = virtual_stack.back();
                        // remove the second element from the stack
                        virtual_stack.pop_back();
                        // get the first element from the stack
                        auto const first = virtual_stack.back();
                        // remove the first element from the stack
                        virtual_stack.pop_back();
                        // add the two elements together
                        auto const result = std::stod(first) - std::stod(second);
                        // add the result to the stack
                        virtual_stack.push_back(std::to_string(result));
                    } else if (tokens[0] == "add") {
                        // check if the stack is empty
                        if (virtual_stack.empty()) {
                            // throw an error
                            throw std::runtime_error("stack is empty");
                        }
                        // check if the stack has only one element
                        if (virtual_stack.size() == 1) {
                            // throw an error
                            throw std::runtime_error("stack has only one element");
                        }
                        // get the second element from the stack
                        auto const second = virtual_stack.back();
                        // remove the second element from the stack
                        virtual_stack.pop_back();
                        // get the first element from the stack
                        auto const first = virtual_stack.back();
            }*/
//		return output;
//	}
//} // namespace q1
