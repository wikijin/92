/*
  Use a stack to find out if a sequence of HTML tags is balanced. 
  Your program will read in the tags, one at a time, such as
  <ol>
  <li>
  </li>
  <li>
  </li>
  </ol>
  If everything is ok, print "OK"
  When you find a closing tag that doesn't match its opening
  tag, print "BAD " followed by the tag name.
  If you reached the end of input and there are missing closing 
  tags, print "UNCLOSED" followed by all unclosed tag names,
  starting with the last unclosed one.  
*/

#include <iostream>

using namespace std;

#include "stack.h"

int main()
{
	string tag;
	Stack tag_stack;
	while (cin >> tag)
	{
		tag = tag.substr(1, tag.length() - 2); // Strip off "<...>"
		if (tag.substr(0, 1) == "/")
		{
			tag = tag.substr(1); // Strip off "/"
            string top = tag_stack.pop();
            if (top != tag)
            {
                cout << "BAD " << tag << endl;
                return 0;
            }
		}
        else
        {
            tag_stack.push(tag);
        }
	}
	if (tag_stack.empty())
		cout << "OK" << endl;
	else
	{
		cout << "UNCLOSED ";
		while (!tag_stack.empty())
			cout << tag_stack.pop() << " ";
		cout << endl;
	}
	
	return 0;
}
