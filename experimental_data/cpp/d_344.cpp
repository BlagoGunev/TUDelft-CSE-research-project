#include <bits/stdc++.h>



int main()

{

    std::stack<char> order;



    char c;

    while ( (c = getchar()) != '\n' && c != EOF )

    {

        order.size() ? order.top() == c ? order.pop() : order.push(c) : order.push(c);

    }



    printf("%s\n", order.size() ? "No" : "Yes");

    return 0;

}