#pragma once
#include <string>

enum class TokenType {
    Identifier,     // идентификатор
    Number,         // число: 123, 42
    LParen,         // левая круглая скобка '('
    RParen,         // правая круглая скобка ')'
    QuoteText,     //текст в ковычке;
    Semicolon,      // точка с запятой ';'
    Ampersand,      // амперсанд '&'
    Equals,         // одиночный знак '=' (присваивание)
    DoubleEquals,   // двойной знак '==' (сравнение)
    End             // конец входа (EOF)
};

struct token{
    TokenType type;
    std::string value;
};

struct statement {
    enum Command_Type {
        Print,
        Declare,
        sum,
        differ,
        mult,
        div
    } type;

    std::string name;
    std::string value;

    enum varType{
        I16_type,
        I32_type,
        F16_type,
        F32_type,
        S16_type,
        S32_type
    } typeVar;
    statement(Command_Type t, const std::string& n, const std::string& v, varType vt)
            : type(t), name(n), value(v), typeVar(vt) {}
};

struct Variable {
    statement::varType type;
    std::string value;
};
