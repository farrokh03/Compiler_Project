#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

static int Counter = 0 ;
static string lookahead;
vector<string> callLog;
//DFAs
class DFA{
    public:
        DFA(){}
       
        enum class TokenType{
            KEYWORD,
            OPERATOR,
            ERROR,
            IDENTIFIER,
            SYNTAX,
            NUMBERS,
        };

        struct Token{
            string value = "";
            TokenType type;
            int line = 0 ;
            int WhichWord = 0 ;
            int index;
        };
        
        Token get_front_of_Token_list(){
            return Tokens.front();
        }

        void erase_front_of_Token_list(){
            Tokens.erase(Tokens.begin());
        }

        void add_to_Token_list(Token object){
            this->Tokens.push_back(object);
        }

        void add_to_Error_Token_list(Token object){
            this->ErrorTokens.push_back(object);
        }

        vector<Token> get_All_Token_list(){
            return AllTokenList;
        }

        void Add_to_All_Token_list(Token object){
            this->AllTokenList.push_back(object);
        }
        
        vector<Token> get_Token_list(){
            return Tokens;
        }

        vector<Token> get_Error_List(){
            return ErrorTokens;
        }

        string FuncDefinition(const string& value) {
            int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {
                letter = value[i];
                switch (state) {
                    case 1:
                        if (letter == '$') {
                            Token += letter;
                            state = 2;
                            i++;
                        } else
                            state = 13;
                        break;
                    case 2:
                        if (letter == 's') {
                            Token += letter;
                            state = 3;
                            i++;
                        } else
                            state = 13;
                        break;
                    case 3:
                        if (letter == 'u') {
                            Token += letter;
                            state = 4;
                            i++;
                        } else 
                            state = 13;
                        break;
                    case 4:
                        if (letter == 'b') {
                            Token += letter;
                            state = 5;
                            i++;
                        } else 
                            state = 13;
                        break;
                    case 5:
                        if (letter == 'o') {
                            Token += letter;
                            state = 6;
                            i++;
                        } else 
                            state = 13;
                        break;
                    case 6:
                        if (letter == 'r') {
                            Token += letter;
                            state = 7;
                            i++;
                        } else 
                            state = 13;
                        break;
                    case 7:
                        if (letter == 'd') {
                            Token += letter;
                            state = 8;
                            i++;
                        } else 
                            state = 13;
                        break;
                    case 8:
                        if (letter == 'i') {
                            Token += letter;
                            state = 9;
                            i++;
                        } else 
                            state = 13;
                        break;
                    case 9:
                        if (letter == 'n') {
                            Token += letter;
                            state = 10;
                            i++;
                        } else 
                            state = 13;
                        break;
                    case 10:
                        if (letter == 'a') {
                            Token += letter;
                            state = 11;
                            i++;
                        } else 
                            state = 13;
                        break;
                    case 11:
                        if (letter == 't') {
                            Token += letter;
                            state = 12;
                            i++;
                        } else 
                            state = 13;
                        break;
                    case 12:
                        if (letter == 'e') {
                            Token += letter;
                            i++;
                            if( i == value.length()){
                                Token = "definition";
                                return Token;
                            }
                            else
                                state = 13; 
                        } else 
                            state = 13;
                        break;
                    case 13:
                        Token.clear();
                        return Token; 
                    default:
                        break;
                }
            }
        }

        string FuncCalling(const string& value) {
            int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {
                letter = value[i];
                switch (state) {
                    case 1:
                        if (letter == 'i') {
                            Token += letter;
                            state = 2;
                            i++;
                        }else
                            state = 11;
                        break;
                    case 2:
                        if (letter == 'n') {
                            Token += letter;
                            state = 3;
                            i++;
                        }else
                            state = 11;
                        break;
                    case 3:
                        if (letter == 'v') {
                            Token += letter;
                            state = 4;
                            i++;
                        }else
                            state = 11;
                        break;
                    case 4:
                        if (letter == 'i') {
                            Token += letter;
                            state = 5;
                            i++;
                        }else
                            state = 11;
                        break;
                    case 5:
                        if (letter == 't') {
                            Token += letter;
                            state = 6;
                            i++;
                        }else
                            state = 11;
                        break;
                    case 6:
                        if (letter == 'a') {
                            Token += letter;
                            state = 7;
                            i++;
                        }else
                            state = 11;
                        break;
                    case 7:
                        if (letter == 't') {
                            Token += letter;
                            state = 8;
                            i++;
                        }else
                            state = 11;
                        break;
                    case 8:
                        if (letter == 'i') {
                            Token += letter;
                            state = 9;
                            i++;
                        }else
                            state = 11;
                        break;
                    case 9:
                        if (letter == 'o') {
                            Token += letter;
                            state = 10;
                            i++;
                        }else
                            state = 11;
                        break;
                    case 10:
                        if (letter == 'n') {
                            Token += letter;
                            i++;
                            if( i == value.length()){
                                Token = "call";
                                return Token;
                            }
                            else
                                state = 11; 
                        }else
                            state = 11;
                        break;
                    case 11:
                        Token.clear();
                        return Token; 
                    default:
                        break;
                }
            }
        }

        string Loop(const string& value) {
            int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {
                letter = value[i];
                switch (state) {
                    case 1:
                        if (letter == '!') {
                            Token += letter;
                            state = 2;
                            i++;
                        }else
                            state = 10;
                        break;
                    case 2:
                        if (letter == 'f') {
                            Token += letter;
                            state = 3;
                            i++;
                        }else
                            state = 10;
                        break;
                    case 3:
                        if (letter == 'o') {
                            Token += letter;
                            state = 4;
                            i++;
                        }else
                            state = 10;
                        break;
                    case 4:
                        if (letter == 'r') {
                            Token += letter;
                            state = 5;
                            i++;
                        }else
                            state = 10;
                        break;
                    case 5:
                        if (letter == 'l') {
                            Token += letter;
                            state = 6;
                            i++;
                        }else
                            state = 10;
                        break;
                    case 6:
                        if (letter == 'o') {
                            Token += letter;
                            state = 7;
                            i++;
                        }else
                            state = 10;
                        break;
                    case 7:
                        if (letter == 'o') {
                            Token += letter;
                            state = 8;
                            i++;
                        }else
                            state = 10;
                        break;
                    case 8:
                        if (letter == 'p') {
                            Token += letter;
                            state = 9;
                            i++;
                        }else
                            state = 10;
                        break;
                    case 9:
                        if (letter == '!') {
                            Token += letter;
                            i++;
                            if( i == value.length()){
                                Token = "for";
                                return Token;
                            }
                            else
                                state = 10; 
                        }else
                            state = 10;
                        break;
                    case 10:
                        Token.clear();
                        return Token; 
                    default:
                        break;
                }
            }
        }

        string Conjunction(const string& value) {
            int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {
                letter = value[i];
                switch (state) {
                    case 1:
                        if (letter == '!') {
                            Token += letter;
                            state = 2;
                            i++;
                        }else
                            state = 8;
                        break;
                    case 2:
                        if (letter == 'c') {
                            Token += letter;
                            state = 3;
                            i++;
                        }else
                            state = 8;
                        break;
                    case 3:
                        if (letter == 'y') {
                            Token += letter;
                            state = 4;
                            i++;
                        }else
                            state = 8;
                        break;
                    case 4:
                        if (letter == 'c') {
                            Token += letter;
                            state = 5;
                            i++;
                        }else
                            state = 8;
                        break;
                    case 5:
                        if (letter == 'l') {
                            Token += letter;
                            state = 6;
                            i++;
                        }else
                            state = 8;
                        break;
                    case 6:
                        if (letter == 'e') {
                            Token += letter;
                            state = 7;
                            i++;
                        }else
                            state = 8;
                        break;
                    case 7:
                        if (letter == '!') {
                            Token += letter;
                            i++;
                            if( i == value.length()){
                                Token = "while";
                                return Token;
                            }else
                                state = 8; 
                        }else
                            state = 8;
                        break;
                    case 8:
                        Token.clear();
                        return Token; 
                    default:
                        break;
                }
            }
        }

        string ID(const string& value) {
            int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {
                letter = value[i];
                switch (state) {
                    case 1:
                        if (letter == '+') {
                            Token += letter;
                            state = 2;
                            i++;
                        }else
                            state = 4;
                        break;
                    case 2:
                        if (letter <= 'z' && letter >='a' || letter <='Z'&& letter >= 'A' || letter >= '0' && letter <= '9' ) {
                            Token += letter;
                            state = 3;
                            i++;
                        }else
                            state = 4;
                        break;
                    case 3:
                        if (letter <= 'z' && letter >='a' || letter <='Z'&& letter >= 'A' || letter >= '0' && letter <= '9' ) {
                            Token += letter;
                            state = 3;
                            i++;
                        }else if( letter == '+'){
                            Token += letter;
                            i++;
                            if( i == value.length()){
                                Token = "ID";
                                return Token;
                            }else
                                state = 4;

                        }else {
                            state = 4;
                        }
                        break;
                    case 4:
                        Token.clear();
                        return Token;
                        break;
                    default:
                        break;
                }
            }
        }

        string Total(const string& value){
        int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {
                letter = value[i];
                switch (state) {
                    case 1:
                        if (letter == 'p') {
                            Token += letter;
                            state = 2;
                            i++;
                        } else
                            state = 3;
                        break;
                    case 2:
                        if (letter == 'l') {
                            Token += letter;
                            i++;
                            if (i == value.length()){
                                Token = "+";
                                return Token;
                            }else{
                                state = 3;
                            }
                        } else
                            state = 3;
                        break;
                    case 3:
                        Token.clear();
                        return Token;
                        break;
                    default:
                        break;
                }
            }
        }

        string Minus(const string& value){
        int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {
                letter = value[i];
                switch (state) {
                    case 1:
                        if (letter == 'd') {
                            Token += letter;
                            state = 2;
                            i++;
                        } else
                            state = 3;
                        break;
                    case 2:
                        if (letter == 'c') {
                            Token += letter;
                            i++;
                            if (i == value.length()){
                                Token = "-";
                                return Token;
                            }else
                                state = 3;
                        } else
                            state = 3;
                        break;
                    case 3:
                        Token.clear();
                        return Token;
                        break;
                    default:
                        break;
                }
            }
        }

        string STR(const string& value){
        int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {

                letter = value[i];

                switch (state) {
                    case 1:
                        if (letter == 's') {
                            Token += letter;
                            state = 2;
                            i++;
                        } else
                            state = 4;
                        break;

                    case 2:
                        if (letter == 't') {
                            Token += letter;
                            state = 3;
                            i++;
                        } else
                            state = 4;
                        break;

                    case 3:
                        if (letter == 'r') {
                            Token += letter;
                            i++;
                            if (i == value.length()){
                                return Token;
                            }else
                                state = 4;
                        } else
                            state = 3;
                        break;

                    case 4:
                        Token.clear();
                        return Token;
                        break;
                    default:
                        break;
                }
            }
        }

        string INT(const string& value){
        int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {

                letter = value[i];
                
                switch (state) {
                    case 1:
                        if (letter == 'i') {
                            Token += letter;
                            state = 2;
                            i++;
                        } else
                            state = 4;
                        break;

                    case 2:
                        if (letter == 'n') {
                            Token += letter;
                            state = 3;
                            i++;
                        } else
                            state = 4;
                        break;

                    case 3:
                        if (letter == 't') {
                            Token += letter;
                            i++;
                            if (i == value.length()){
                                return Token;
                            }else
                                state = 4;
                        } else
                            state = 3;
                        break;

                    case 4:
                        Token.clear();
                        return Token;
                        break;
                    default:
                        break;
                }
            }
        }

        string Multiplication(const string& value){
        int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {
                letter = value[i];
                switch (state) {
                    case 1:
                        if (letter == 'c') {
                            Token += letter;
                            state = 2;
                            i++;
                        } else
                            state = 3;
                        break;
                    case 2:
                        if (letter == 'o') {
                            Token += letter;
                            i++;
                            if (i == value.length()){
                                Token = "*";
                                return Token;
                            }else
                                state = 3;
                        } else
                            state = 3;
                        break;
                    case 3:
                        Token.clear();
                        return Token;
                        break;
                    default:
                        break;
                }
            }
        }

        string Division(const string& value){
        int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {
                letter = value[i];
                switch (state) {
                    case 1:
                        if (letter == 'd') {
                            Token += letter;
                            state = 2;
                            i++;
                        } else
                            state = 3;
                        break;
                    case 2:
                        if (letter == 'b') {
                            Token += letter;
                            i++;
                            if (i == value.length()){
                                Token = "/";
                                return Token;
                            }else
                                state = 3;
                        } else
                            state = 3;
                        break;
                    case 3:
                        Token.clear();
                        return Token;
                        break;
                    default:
                        break;
                }
            }
        }

        string Quantification(const string& value){
        int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {
                letter = value[i];
                switch (state) {
                    case 1:
                        if (letter == 's') {
                            Token += letter;
                            state = 2;
                            i++;
                        } else
                            state = 3;
                        break;
                    case 2:
                        if (letter == 'v') {
                            Token += letter;
                            i++;
                            if (i == value.length()){
                                Token = "=";
                                return Token;
                            }else
                                state = 3;
                        } else
                            state = 3;
                        break;
                    case 3:
                        Token.clear();
                        return Token;
                        break;
                    default:
                        break;
                }
            }
        }

        string Equal(const string& value){
        int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {
                letter = value[i];
                switch (state) {
                    case 1:
                        if (letter == 'a') {
                            Token += letter;
                            state = 2;
                            i++;
                        } else
                            state = 6;
                        break;
                        case 2:
                        if (letter == 'l') {
                            Token += letter;
                            state = 3;
                            i++;
                        } else
                            state = 6;
                        break;
                        case 3:
                        if (letter == 'i') {
                            Token += letter;
                            state = 4;
                            i++;
                        } else
                            state = 6;
                        break;
                        case 4:
                        if (letter == 'k') {
                            Token += letter;
                            state = 5;
                            i++;
                        } else
                            state = 6;
                        break;
                    case 5:
                        if (letter == 'e') {
                            Token += letter;
                            i++;
                            if (i == value.length()){
                                Token = "=";
                                return Token;
                            }else{
                                state = 6;
                            }
                        } else
                            state = 6;
                        break;
                    case 6:
                        Token.clear();
                        return Token;
                        break;
                    default:
                        break;
                }
            }
        }

        string OpenParenthesis(const string& value){
        int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {
                letter = value[i];
                switch (state) {
                    case 1:
                        if (letter == '(') {
                            Token += letter;
                            i++;
                            if (i == value.length()){
                                return Token;
                            }else
                                state = 2;
                        } else
                            state = 2;
                        break;
                    case 2:
                        Token.clear();
                        return Token;
                        break;
                    default:
                        break;
                }
            }
        }  

        string CloseParenthesis(const string& value){
        int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {
                letter = value[i];
                switch (state) {
                    case 1:
                        if (letter == ')') {
                            Token += letter;
                            i++;
                            if (i == value.length()){
                                return Token;
                            }else
                                state = 2;
                        } else
                            state = 2;
                        break;
                    case 2:
                        Token.clear();
                        return Token;
                        break;
                    default:
                        break;
                }
            }
        }

        string TwoPoints(const string& value){
        int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {
                letter = value[i];
                switch (state) {
                    case 1:
                        if (letter == ':') {
                            Token += letter;
                            i++;
                            if (i == value.length()){
                                return Token;
                            }else
                                state = 2;
                        } else
                            state = 2;
                        break;
                    case 2:
                        Token.clear();
                        return Token;
                        break;
                    default:
                        break;
                }
            }
        }

        string OpenBraces(const string& value){
        int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {
                letter = value[i];
                switch (state) {
                    case 1:
                        if (letter == '{') {
                            Token += letter;
                            i++;
                            if (i == value.length()){
                                return Token;
                            }else
                                state = 2;
                        } else
                            state = 2;
                        break;
                    case 2:
                        Token.clear();
                        return Token;
                        break;
                    default:
                        break;
                }
            }
        }

        string CloseBraces(const string& value){
        int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {
                letter = value[i];
                switch (state) {
                    case 1:
                        if (letter == '}') {
                            Token += letter;
                            i++;
                            if (i == value.length()){
                                return Token;
                            }else
                                state = 2;
                        } else
                            state = 2;
                        break;
                    case 2:
                        Token.clear();
                        return Token;
                        break;
                    default:
                        break;
                }
            }
        }

        string Unknown(const string& value){
            return value;
        }

        string Numbers(const string& value){
            int state = 1;
            int i = 0 ;
            char letter ;
            string Token = "";
            while (i < value.length()){
                letter = value[i];
                switch (state)
                {
                case 1:
                    if( letter >= '1' && letter <= '9' ){
                        Token += letter;
                        i++;
                        state = 2 ;
                    }else
                        state = 3;
                    break;
                case 2:
                    if(letter >= '0' && letter <= '9'){
                        Token += letter;
                        i++;
                        state = 2;
                    }else
                        state = 3;
                    break;
                case 3:
                    Token.clear();
                    return Token;
                    break;
                
                default:
                    break;
                }
            }
            Token = "Number";
            return Token;
        }

        string Condition(const string& value) {

            int state = 1;
            string Token;
            char letter;
            int i = 0;
            while (i < value.length()) {
                letter = value[i];
                switch (state) {
                    case 1:
                        if (letter == '!') {
                            Token += letter;
                            state = 2;
                            i++;
                        } else
                            state = 12;
                        break;
                    case 2:
                        if (letter == 'c') {
                            Token += letter;
                            state = 3;
                            i++;
                        } else
                            state = 12;
                        break;
                    case 3:
                        if (letter == 'o') {
                            Token += letter;
                            state = 4;
                            i++;
                        } else
                            state = 12;
                        break;
                    case 4:
                        if (letter == 'n') {
                            Token += letter;
                            state = 5;
                            i++;
                        } else
                            state = 12;
                        break;
                    case 5:
                        if (letter == 'd') {
                            Token += letter;
                            state = 6;
                            i++;
                        } else
                            state = 12;
                        break;
                    case 6:
                        if (letter == 'i') {
                            Token += letter;
                            state = 7;
                            i++;
                        } else
                            state = 12;
                        break;
                    case 7:
                        if (letter == 't') {
                            Token += letter;
                            state = 8;
                            i++;
                        } else 
                            state = 12;
                        break;
                    case 8:
                        if (letter == 'i') {
                            Token += letter;
                            state = 9;
                            i++;
                        } else
                            state = 12;
                        break;
                    case 9:
                        if (letter == 'o') {
                            Token += letter;
                            state = 10;
                            i++;
                        } else
                            state = 12;
                        break;
                    case 10:
                        if (letter == 'n') {
                            Token += letter;
                            state = 11;
                            i++;
                        } else
                            state = 12;
                        break;
                    case 11:
                        if (letter == '!') {
                            Token += letter;
                            i++;
                            if( i == value.length()){
                                Token = "if";
                                return Token;
                            }
                            else
                                state = 12; 
                        } else
                            state = 12;
                        break;
                    case 12:
                        Token.clear();
                        return Token; 
                    default:
                        break;
                }
            }
        }
        
        string FloatNumbers(const string& value){
            int state = 1;
            int i = 0 ;
            char letter ;
            string Token = "";
            while (i < value.length()){
                letter = value[i];
                switch (state)
                {
                case 1:
                    if( letter >= '0' && letter <= '9' ){
                        Token += letter;
                        i++;
                        state = 2 ;
                    }else
                        state = 4;
                    break;
                case 2:
                    if(letter >= '0' && letter <= '9'){
                        Token += letter;
                        i++;
                        state = 2;
                    }else if(letter == '.'){
                        Token += letter;
                        i++;
                        state = 3;
                    }else
                        state = 4;
                    break;
                case 3:
                    if(letter >= '0'&& letter <='9'){
                        Token += letter;
                        i++;
                        state = 3;
                    }else
                        state = 4;
                    break;
                case 4:
                    Token.clear();
                    return Token;
                    break;
                default:
                    break;
                }
            }
            Token = "Number";
            return Token;
        }

        string elseif(const string& value){
        
            int state = 1;
            int i = 0 ;
            char letter ;
            string Token = "";
            while (i < value.length()){
                letter = value[i];
                switch (state)
                {
                case 1:
                    if( letter == 'e' ){
                        Token += letter;
                        i++;
                        state = 2 ;
                    }else
                        state = 7;
                    break;
                case 2:
                    if(letter =='l'){
                        Token += letter;
                        i++;
                        state = 3;
                    }else
                        state = 7;
                case 3:
                    if( letter == 's' ){
                        Token += letter;
                        i++;
                        state = 4 ;
                    }else
                        state = 7;
                    break;
                case 4:
                    if( letter == 'e' ){
                        Token += letter;
                        i++;
                        state = 5 ;
                    }else
                        state = 7;
                    break;
                case 5:
                    if( letter == 'i' ){
                        Token += letter;
                        i++;
                        state = 6 ;
                    }else
                        state = 7;
                    break;
                case 6:
                    if (letter == 'f') {
                            Token += letter;
                            i++;
                            if( i == value.length()){
                                Token = "elseif";
                                return Token;
                            }
                            else
                                state = 12;
                    }else
                        state = 7;
                    break;
                case 7:
                    Token.clear();
                    return Token;
                    break;
                default:
                    break;
                }
            }
            return Token;

        }
    
        string gamma(const string& value){
            string Token="";
            if(value.length() == 1 && value == ",")
                Token = value;
            return Token;    
        }

        string DollerSign(const string& value){
            string Token = "";
            if (value.length() == 1 && value == "$")
                Token = value;
            return Token;
        }

        string SharpSign(const string& value){
            string Token;
            if (value.length() == 1 &&  value == "#")
                Token = value;
            return Token;
        }

        string elsescope(const string& value){
            int state = 1;
            int i = 0 ;
            char letter ;
            string Token = "";
            while (i < value.length()){
                letter = value[i];
                switch (state)
                {
                case 1:
                    if( letter == 'e' ){
                        Token += letter;
                        i++;
                        state = 2 ;
                    }else
                        state = 5;
                    break;
                case 2:
                    if(letter =='l'){
                        Token += letter;
                        i++;
                        state = 3;
                    }else
                        state = 5;
                case 3:
                    if( letter == 's' ){
                        Token += letter;
                        i++;
                        state = 4 ;
                    }else
                        state = 5;
                    break;
                case 4:
                    if( letter == 'e' ){
                            Token += letter;
                            i++;
                            if( i == value.length()){
                                Token = "else";
                                return Token;
                            }
                            else
                                state = 5;
                    }else
                        state = 5;
                    break;                    
                case 5:
                    Token.clear();
                    return Token;
                    break;
                default:
                    break;
                }
            }
            return Token;

        }
    private:
        vector<Token> Tokens;
        vector<Token> ErrorTokens;
        vector<Token> AllTokenList;

};
//first phase
DFA globalobject;

vector<string> Spilit_By_White_Space(const string& line) {
    istringstream stream(line);
    string word;
    vector<string> words;
    while (stream >> word)
        words.push_back(word);
    return words;
}

DFA::Token Token_Value_Setter(const string& value){
    DFA::Token obj;
    DFA object;
        obj.value = object.Quantification(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.FuncCalling(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.FuncDefinition(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.Loop(value);
    if(!obj.value.empty())
        return   obj ;
    else
        obj.value = object.Conjunction(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.OpenBraces(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.Equal(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.Minus(value);
    if(!obj.value.empty())
        return  obj;
    else
        obj.value = object.Condition(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.Total(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.ID(value); 
     if(!obj.value.empty())
        return obj;
    else
        obj.value = object.CloseBraces(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.OpenParenthesis(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.CloseParenthesis(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.TwoPoints(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.Multiplication(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.Division(value);
    if(!obj.value.empty())
        return obj; 
    else    
        obj.value = object.Numbers(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.FloatNumbers(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.STR(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.INT(value);
    if(!obj.value.empty())
        return obj;
    else
         obj.value = object.elseif(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.elsescope(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.gamma(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.DollerSign(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.SharpSign(value);
    if(!obj.value.empty())
        return obj;
    else
        obj.value = object.Unknown(value);
    return obj;
}

DFA::Token Token_Type_Setter(string& value){
    DFA::Token obj;
    if (value == "!condition!"||value == "!cycle!"||value == "!forloop!"||value == "$subordinate"||value == "invitation" ||value == "else"|| value =="elseif" || value =="str" || value =="int" )
        obj.type =  DFA::TokenType(0);
    else if (value == ")"|| value =="("||value == "{"||value == "}" || value == ":"||value == "," ||value =="$"||value =="#")
        obj.type = DFA::TokenType(4);
    else if (value[0] == '+'&& value[value.length()-1] == '+'&& value.length()>2)
        obj.type = DFA::TokenType(3);
    else if (value == "sv" || value == "pl"||value == "co"|| value =="db"||value == "alike"||value == "dc"|| value == "<<" || value == ">>")
        obj.type = DFA::TokenType(1);
    else if (value[0] >= '0' && value[0] <= '9')
        obj.type = DFA::TokenType(5);
    else 
        obj.type = DFA::TokenType(2);
    return obj;
}

int Index_Setter(int index){
    return index;
}

DFA File_Reader(string value){
    DFA::Token obj;
    fstream File(value);
    DFA object;
    if(!File.is_open())
        cerr<<"Faild to Open File ."<<endl;
    int lineNumber = 1;
    int Coulmn = 0 ;
    string word;
    string Line;
    while(getline(File,Line)){
        vector<string> words = Spilit_By_White_Space(Line);
        for(string&word : words){
            Coulmn++;

            obj.value = Token_Value_Setter(word).value;
            obj.type = Token_Type_Setter(word).type;
            obj.line = lineNumber;
            obj.WhichWord = Coulmn;
            Counter ++;
            obj.index = Counter;
            if(obj.type == DFA::TokenType::ERROR){
                object.add_to_Error_Token_list(obj);
                Counter --;
            }
            if( obj.type != DFA::TokenType::ERROR)
                 object.add_to_Token_list(obj);
            object.Add_to_All_Token_list(obj);
        }
        Coulmn = 0;
        lineNumber++;    
    }
    return object;
}

string Token_Type_To_String(DFA::Token object){
    if(object.type == DFA::TokenType::IDENTIFIER){
        return "Identifier";
    }else if(object.type == DFA::TokenType::KEYWORD){
        return "Keyword";
    }else if (object.type == DFA::TokenType::NUMBERS){
        return "Numbers";
    }else if(object.type == DFA::TokenType::OPERATOR){
        return "Operator";
    }else if (object.type == DFA::TokenType::SYNTAX){
        return "Syntax";
    }else
        return "Error";
}

int matchcharacters(string firstvalue , string secondvalue){
    int i = 0;
    int counter = 0;
    for(char ch : firstvalue){
        if(firstvalue[i] == secondvalue[i]) 
            counter = counter;
        else 
            counter++;
        i++;
        if(i < min(firstvalue.length(),secondvalue.length()))
            continue;
    }
    return counter + max(firstvalue.length(),secondvalue.length()) - min(firstvalue.length(),secondvalue.length());
}

string Error_Token_Description(DFA::Token object){  
    int state = 1;
    string word;
    int check;
    while(true){
        switch (state)
        {
            case 1:word = "!condition!";
                check = matchcharacters(object.value,word);
                if( check<=1 ){
                    return "This error is similar to the condition keyword which is written in reverse is : !condition!";
                }else
                    state = 2;
                break;
            case 2: word = "!cycle!";
                check = matchcharacters(object.value,word);
                if( check<=1 ){
                    return "This error is similar to the while keyword which is written in reverse is : !cycle!";
                }else
                    state = 3;
                break;
            case 3: word = "!forloop!";
                check = matchcharacters(object.value,word);
                if( check<=1 ){
                    return "This error is similar to the for keyword which is written in reverse is : !forloop!";
                }else
                    state = 4;
                break;
            case 4: word = "$subordinate";
                check = matchcharacters(object.value,word);
                if( check<=1 ){
                    return "This error is similar to the function definition keyword which is written in reverse is : $subordinate";
                }else
                    state = 5;
                break;
            case 5: word = "invitation";
                check = matchcharacters(object.value,word);
                if( check<=1 ){
                    return "This error is similar to the function calling keyword which is written in reverse is : invitation";
                }else
                    state = 6;
                break;
            case 6: word = "sv";
                check = matchcharacters(object.value,word);
                if( check<=1 ){
                    return "This error is similar to the equal operator which is written in reverse is : sv";
                }else
                    state = 7;
                break;
            case 7: word = "pl";
                check = matchcharacters(object.value,word);
                if( check<=1 ){
                    return "This error is similar to the plus operator which is written in reverse is : pl";
                }else
                    state = 8;
                break;
            case 8: word = "co";
                check = matchcharacters(object.value,word);
                if( check<=1 ){
                    return "This error is similar to the multiplication operator which is written in reverse is : co";
                }else
                    state = 9;
                break;
            case 9: word = "db";
                check = matchcharacters(object.value,word);
                if( check<=1 ){
                    return "This error is similar to the devide operator which is written in reverse is : db";
                }else
                    state = 10 ;
                break;
            case 10:
                word.clear();
                return "this is an unknown word .";
                break;
            default:
                break;
        }
    }
}

void Tokens_Display(vector<DFA::Token>Errors ,vector<DFA::Token>Tokens,string filename){ 
    for (DFA::Token obj:Tokens){
        string type = Token_Type_To_String(obj);
        if(obj.type != DFA::TokenType::ERROR){
                cout<<setw(2)<<left<<obj.index<<"  ---->  " <<setw(13)<<"Token Type : "<<setw(10)<<left<<type<<"  "<<setw(13)<<"Token value: "<<setw(19)<<left<< 
                obj.value<<"  "<<setw(12)<<"Token line: "<<setw(2)<<left<<obj.line<<"     "
                <<" Which word of line: "<<setw(2)<<left<<obj.WhichWord<<endl;
            }
    }
    cout<<endl<<endl;
    for(DFA::Token obj2 : Errors)
        cout<<"line "<<obj2.line<<": "<<"<< "<<obj2.value<<" >>  "<<Error_Token_Description(obj2)<<endl;
}

//second phase
void File_Writer(vector<DFA::Token> TokenList){
    ofstream outputfile("output.txt");
    outputfile << "";
    if ( !outputfile.is_open())
        cerr << "Faild to insert Tokens to Output file.";
    
    for (DFA::Token obj : TokenList )
        outputfile << obj.value << endl;
}
void logCall(const string& caller, const string& callee) {
    callLog.push_back(caller + " ------> " + callee);
}
void printCallLog(ofstream& file) {
    file <<"";
    for (const auto& log : callLog) {
        file << log << endl;
    }
}
bool Check_Tokens_for_Syntactic_phase(vector<DFA::Token>AllTokenList){
    for (DFA::Token obj:AllTokenList){
        if (obj.type == DFA::TokenType::ERROR)
            return true;
    }
    return false;
}
void targetFunction(const string& caller,const string& collee ="MatchFunction") {
    logCall(caller, collee);
}
string get_Token(){

    DFA::Token obj = globalobject.get_front_of_Token_list();
    globalobject.erase_front_of_Token_list();
    return obj.value;
}
//declare analyzer functions
void Start();void syntax();void Commands();void Setvalue();void Declare();void M();void Type();void DecFinput();void D();void Finput();
void P();void X();void Content();void K();void Comparator();void Notif();void T();void OP();void Action();
//main function
int main() {
    string filename;
    cout<<"write file name :"<<endl;
    cin >>filename;
    globalobject = File_Reader(filename);
    vector<DFA::Token> Tokens = globalobject.get_Token_list();
    vector<DFA::Token> Errors = globalobject.get_Error_List();
    Tokens_Display(Errors,Tokens,filename);
    File_Writer(Tokens);
    if (Check_Tokens_for_Syntactic_phase(globalobject.get_All_Token_list())){
        cout<<"An error was found in the lexical phase section.\n Please correct the errors in this section first so that the syntactic phase can be executed."<<endl;
        exit(0);
    }else{
        cout<<"Lexical phase execution is complete.\nAll tokens are approved. Syntactic phase execution begins."<<endl;
        lookahead = get_Token();
        Start();
        cout<<"syntax Error Detected .";
    }
    return 0;
}

void  MatchFunction (string value){
    if ( value == lookahead ){
        lookahead = get_Token();
    }else{
        cout<<"syntax Error Detected . ";
        exit(0);
    }
}
void Start(){
    if (lookahead == "for" || lookahead == "while" || lookahead == "call" || lookahead == "definition" ||lookahead =="if"){
            targetFunction("Start","Syntax");
            syntax();
    }else if (lookahead == "ID" || lookahead == "str" || lookahead == "int"){
        targetFunction("Start","Commands");
        Commands();
    }else if (lookahead == "$"){
        ofstream logfile("function_call_logs.txt");
        printCallLog(logfile);
        cout<<endl<<endl<<"compiled successfully."<<endl;
        exit(0);
    }else if ( lookahead == "#"){
        return;
    }else{
        cout<<"syntax Error on Start"<<endl;
        exit(0);
    }
    return;

}
void syntax(){
    if(lookahead == "if"){
        targetFunction("syntax");
        MatchFunction("if");
        targetFunction("syntax");
        MatchFunction("(");
        targetFunction("syntax","Comparator");
        Comparator();
        targetFunction("syntax");
        MatchFunction(")");
        targetFunction("syntax");
        MatchFunction("{");
        targetFunction("syntax","Content");
        Content();
        targetFunction("syntax");
        MatchFunction("}");
        targetFunction("syntax","Notif");
        Notif();

    }else if (lookahead == "for"){
        targetFunction("syntax");
        MatchFunction("for");
        targetFunction("syntax");
        MatchFunction("(");
        targetFunction("syntax","Action");
        Action();
        targetFunction("syntax");
        MatchFunction(",");
        targetFunction("syntax","Comparator");
        Comparator();
        targetFunction("syntax");
        MatchFunction(",");
        targetFunction("syntax","Action");
        Action();
        targetFunction("syntax");
        MatchFunction(")");
        targetFunction("syntax");
        MatchFunction("{");
        targetFunction("syntax","Content");
        Content();
        targetFunction("syntax");
        MatchFunction("}");
        targetFunction("syntax","Start");
        Start();

    }else if (lookahead == "while"){
        targetFunction("syntax");
        MatchFunction("while");
        targetFunction("syntax");
        MatchFunction("(");
        targetFunction("syntax","Comparator");
        Comparator();
        targetFunction("syntax");
        MatchFunction(")");
        targetFunction("syntax");
        MatchFunction("{");
        targetFunction("syntax","Content");
        Content();
        targetFunction("syntax");
        MatchFunction("}");
        targetFunction("syntax","Start");
        Start();

    }else if (lookahead == "call"){
        targetFunction("syntax");
        MatchFunction("call");
        targetFunction("syntax");
        MatchFunction("ID");
        targetFunction("syntax");
        MatchFunction("(");
        targetFunction("syntax","Finput");
        Finput();
        targetFunction("syntax");
        MatchFunction(")");
        targetFunction("syntax");
        MatchFunction(":");

    }else if (lookahead == "definition"){
        targetFunction("syntax");
        MatchFunction("definition");
        targetFunction("syntax");
        MatchFunction("ID");
        targetFunction("syntax");
        MatchFunction("(");
        targetFunction("syntax","DecFinput");
        DecFinput();
        targetFunction("syntax");
        MatchFunction(")");
        targetFunction("syntax");
        MatchFunction("{");
        targetFunction("syntax","Content");
        Content();
        targetFunction("syntax");
        MatchFunction("}");
        targetFunction("syntax","Start");
        Start();
    }else if (lookahead == "$" || lookahead == "}" || lookahead == "#" || lookahead == "str" || lookahead == "int" || lookahead == "ID" )
        return;
    else{
        cout<<"syntax Error on Syntax"<<endl;
        exit(0);
    }
    return;
}
void Commands(){
    if(lookahead == "ID"){
        targetFunction("Commands","Setvalue");
        Setvalue();
        targetFunction("Commands","Start");
        Start();
    }else if (lookahead == "str" || lookahead == "int"){
        targetFunction("Commands","Declare");
        Declare();
        targetFunction("Commands","Start");
        Start();
    }else if (lookahead == "if" || lookahead == "for" || lookahead =="while" || lookahead =="call" || lookahead =="definition"||lookahead =="$" || lookahead =="#")
        return;
    else{
        cout<<"syntax Error on Commands"<<endl;
        exit(0);
    }
    return;
}
void Setvalue(){
    
    if (lookahead == "ID"){
        targetFunction("Setvalue");
        MatchFunction("ID");
        targetFunction("Setvalue");
        MatchFunction("=");
        targetFunction("Setvalue","Action");
        Action();
    }else if (lookahead == "if" || lookahead =="while" || lookahead == "for" || lookahead =="call"|| lookahead =="definition" || lookahead == "str" ||lookahead =="int")
        return;
    else{
        cout<<"syntax Error on Setvalue"<<endl;
        exit(0);
    }
    return;
}
void Declare(){
    if(lookahead == "str" || lookahead == "int"){
        targetFunction("Declare","Type");
        Type();
        targetFunction("Declare");
        MatchFunction("ID");
        targetFunction("Declare","M");
        M();
    }else if (lookahead == "if" || lookahead =="while" || lookahead == "for" || lookahead =="call"|| lookahead =="definition"||lookahead =="ID")
        return;
    else{
        cout<<"syntax Error on Declare"<<endl;
        exit(0);
    }
}
void M(){
    if(lookahead == ":"){
        targetFunction("M");
        MatchFunction(":");
    }
    else if (lookahead == "="){
        targetFunction("M");
        MatchFunction("=");
        targetFunction("M","Action");
        Action();
    }else if (lookahead == "if" || lookahead =="while" || lookahead == "for" || lookahead =="call"|| lookahead =="definition"||lookahead =="ID"||lookahead =="int"||lookahead =="str")
        return;
    else{
        cout<<"syntax Error on M"<<endl;
        exit(0);
    }
}
void Type(){
    if (lookahead == "str"){
        targetFunction("Type");
        MatchFunction("str");
    }
    else if (lookahead == "int"){
        targetFunction("Type");
        MatchFunction("int");
    }
    else if ( lookahead =="ID")
        return;
    else{
        cout<<"syntax Error on Type"<<endl;
        exit(0);
    }
}
void DecFinput(){
    if (lookahead == "str" || lookahead == "int"){
        targetFunction("DecFinput","Type");
        Type();
        targetFunction("DecFinput");
        MatchFunction("ID");
        targetFunction("DecFinput","D");
        D();
    }else{
        cout<<"syntax Error on DecFinput"<<endl;
        exit(0);
    } 
    return;
}
void D(){
    if (lookahead == ","){
        targetFunction("D");
        MatchFunction(",");
        targetFunction("D","DecFinput");
        DecFinput();
    }else if (lookahead == ")"){
        return;
    }else{
        cout<<"syntax Error on D"<<endl;
        exit(0);
    }
    return;
}
void Finput(){
    if (lookahead == "ID"){
        targetFunction("Finput");
        MatchFunction("ID");
        targetFunction("Finput","X");
        X();    
    }else if (lookahead == "number"){
        targetFunction("Finput");
        MatchFunction("Number");
        targetFunction("Finput","X");
        X();
    }else if (lookahead ==")")
        return;
    else{
        cout<<"syntax Error on Finput"<<endl;
        exit(0);
    }
    return;
}
void X(){
    if (lookahead == ","){
        targetFunction("X");
        MatchFunction(",");
        targetFunction("X","Finput");
        Finput();
    }else if (lookahead==")")
        return;
    else{
        cout<< "syntax Error on X"<<endl;
        exit(0);
    }
    return;
}
void Content(){
    if (lookahead == "for" || lookahead == "while" || lookahead == "call" || lookahead == "definition" ||lookahead =="if"){
            targetFunction("Content","syntax");
            syntax();
            targetFunction("Content","P");
            P();
    }else if (lookahead == "ID" || lookahead == "str" || lookahead == "int"){
            targetFunction("Content","Commands");
            Commands();
            targetFunction("Content","P");
            P();
    }else if (lookahead == "}" || lookahead =="$" || lookahead =="#"){
        return;
    }
    else{
        cout<<lookahead;
        cout<<"Error detected on Content";
        exit(0);
    }
return;
}
void P (){
    if (lookahead == "for" || lookahead == "while" || lookahead == "call" || lookahead == "definition" ||lookahead =="if"||lookahead == "ID" || lookahead == "str" || lookahead == "int"){
        targetFunction("P","Content");
        Content();
        targetFunction("P","P");
        P();
    }else if (lookahead =="#"){
            targetFunction("P");
            MatchFunction("#");
    }
    else if (lookahead == "}" || lookahead =="$"){
        return;
    }else{
        cout<<"Error detected on P";
        exit(0);
    }
    return;
}
void K(){
    if (lookahead == "<<"){
        targetFunction("K");
        MatchFunction("<<");
        targetFunction("K");
        MatchFunction("ID");
    }else if (lookahead == ">>"){
        targetFunction("K");
        MatchFunction(">>");
        targetFunction("K");
        MatchFunction("ID");
    }else if (lookahead == "="){
        targetFunction("K");
        MatchFunction("=");
        targetFunction("K");
        MatchFunction("ID");
    }else if (lookahead ==")" || lookahead ==",")
        return;
    else{
        cout<<"Error has detected on K";
        exit(0);
    }
        
    return;
}
void Comparator(){
    if ( lookahead == "ID"){
        targetFunction("Comparator");
        MatchFunction("ID");
        targetFunction("Comparator","K");
        K();
    }else if (lookahead ==")" || lookahead ==",")
        return;
    else{
        cout<<"Error has detected on Comparator";
        exit(0);
    }
    return;
}
void Notif(){
    if (lookahead == "elseif"){
        targetFunction("Notif");
        MatchFunction("elseif");
        targetFunction("Notif");
        MatchFunction("(");
        targetFunction("Notif","Comparator");
        Comparator();
        targetFunction("Notif");
        MatchFunction(")");
        targetFunction("Notif");
        MatchFunction("{");
        targetFunction("Notif","Content");
        Content();
        targetFunction("Notif");
        MatchFunction("}");
        targetFunction("Notif","Notif");
        Notif();
    }else if (lookahead == "else"){
        targetFunction("Notif");
        MatchFunction("else");
        targetFunction("Notif");
        MatchFunction("{");
        targetFunction("Notif","Content");
        Content();
        targetFunction("Notif");
        MatchFunction("}");
        targetFunction("Notif","Start");
        Start();
    }else if (lookahead == "for" || lookahead == "while" || lookahead == "call" || lookahead == "definition" ||lookahead =="if"||lookahead == "ID" || lookahead == "str" || lookahead == "int"||lookahead=="$"){
        targetFunction("Notif","Start");
        Start();
    }else if (lookahead == "}"||lookahead =="#"){
        return;
    }else{
        cout<<"syntax Error on Notif"<<endl;
        exit(0);    
    }
}
void T(){
    if(lookahead == "*"||lookahead == "/"||lookahead == "+"||lookahead == "-" ||lookahead =="="){
        targetFunction("T","OP");
        OP();
        targetFunction("T","Action");
        Action();
    }else if(lookahead ==":"){
        targetFunction("T");
        MatchFunction(":");
    }else{
        cout<<"syntax Error detected on T"<<endl;
        exit(0);
    }
    return;
}
void OP(){
    if (lookahead == "+"){
        targetFunction("OP");
        MatchFunction("+");
    }
    else if (lookahead == "-"){
        targetFunction("OP");
        MatchFunction("-");
    }
    else if (lookahead =="="){
        targetFunction("OP");
        MatchFunction("=");
    }
    else if (lookahead == "*"){
        targetFunction("OP");
        MatchFunction("*");
    }
    else if (lookahead == "/"){
        targetFunction("OP");
        MatchFunction("/");
    }
    else if (lookahead=="ID"||lookahead =="number")
        return;
    else{
        cout<<"syntax Error on OP"<<endl;
        exit(0);
    }
    return;
}
void Action(){
    if(lookahead == "ID"){
        targetFunction("Action");
        MatchFunction("ID");
        targetFunction("Action","T");
        T();
    }else if (lookahead == "Number"){
        targetFunction("Action");
        MatchFunction("Number");
        targetFunction("Action","T");
        T();
    }else if (lookahead == "$"||lookahead == "if" || lookahead == "for" || lookahead =="while" || lookahead =="call" || lookahead =="definition"|| lookahead =="#"||lookahead=="str"||lookahead=="int"||lookahead==")"||lookahead ==","||lookahead =="$")
        return;
    else{
        cout<<"syntax Error on Action"<<endl;
        exit(0);
    }
    return;

}