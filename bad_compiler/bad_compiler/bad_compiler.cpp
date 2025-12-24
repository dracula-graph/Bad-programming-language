#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "../const.h"
#include "bad_compiler.h"

int getValue(const std::string& input, const std::unordered_map<std::string, Variable>& vars) {
    try {
        return std::stoi(input);
    } catch (...) {
        if (vars.find(input) != vars.end()) {
            return std::stoi(vars.at(input).value);
        }
        throw std::runtime_error("Unknown variable or number: " + input);
    }
}

void bad_compiler(std::vector<statement>& parser_data){

    std::unordered_map<std::string, Variable> variables;

    for (auto& stmt : parser_data) {
        switch (stmt.type) {
            case statement::Command_Type::Print:{
                auto it = variables.find(stmt.value);
                    if (it != variables.end()) {
                        std::cout << it->second.value << std::endl;
                    } else {
                        std::cout << stmt.value << std::endl;
                    }
                break;
            }
            case statement::Command_Type::Declare:{
                if (variables.find(stmt.name) != variables.end())
                    throw std::runtime_error("Variable already exists: " + stmt.name);

                variables[stmt.name] = {
                stmt.typeVar,
                stmt.value
                };
                break;
            }
            case statement::Command_Type::sum:{
                int first = getValue(stmt.name, variables);
                int last = getValue(stmt.value, variables);

                int result = first + last;

                if (variables.find(stmt.name) != variables.end()) {
                    std::stoi(variables.at(stmt.name).value = std::to_string(result));
                }

                break;
            }
            case statement::Command_Type::div:{
                int first = getValue(stmt.name, variables);
                int last = getValue(stmt.value, variables);

                int result = first - last;

                if (variables.find(stmt.name) != variables.end()) {
                    std::stoi(variables.at(stmt.name).value = std::to_string(result));
                }

                break;
            }
            case statement::Command_Type::mult:{
                int first = getValue(stmt.name, variables);
                int last = getValue(stmt.value, variables);

                int result = first * last;

                if (variables.find(stmt.name) != variables.end()) {
                    std::stoi(variables.at(stmt.name).value = std::to_string(result));
                }

                break;
            }
            case statement::Command_Type::differ:{
                int first = getValue(stmt.name, variables);
                int last = getValue(stmt.value, variables);

                int result = first / last;

                if (variables.find(stmt.name) != variables.end()) {
                    std::stoi(variables.at(stmt.name).value = std::to_string(result));
                }

                break;
            }
        }
    }

}
