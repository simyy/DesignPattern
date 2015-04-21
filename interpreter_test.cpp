#include "interpreter.h"

int main(int argc, char** argv)
{
    char s[] = "a+b-c";
    Context* ct = new Context(s);

    int len = ct->get_len();
    cout<<"len:\t"<<len<<endl;

    stack<AbstractExpression*> st;
    for (int i = 0; i < len; i++) {
        char p = ct->get(i);
        if (('+' == p) || ('-' == p) || ('*' == p) || ('/' == p)) {
            AbstractExpression* left = st.top();
            cout<<left->Interpret(ct)<<endl;
            st.pop();
            AbstractExpression* right = new TerminalExpression(i+1);
            st.push(new NotTerminalExpression(i++, left, right));
        }
        else {
            st.push(new TerminalExpression(i));
        } 
    }

    AbstractExpression* result = st.top();
    cout<<"result:\t"<<result->Interpret(ct)<<endl;

    delete ct;
    return 0;
}
