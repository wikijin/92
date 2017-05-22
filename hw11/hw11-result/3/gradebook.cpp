#include "gradebook.h"

/**
	Now we change the gradebook again so that one can increment the
	score of a task (like in the first program).
*/

void GradeBook::add_student(string student)
{
	map<string, int> tasks;
    pair<string, map<string, int> > item(student, tasks);
    scores.insert(item);
}

void GradeBook::add_score(string student, string task, int score)
{
    map<string, int>::iterator it = scores[student].find(task);
    if (it != scores[student].end())
    	scores[student][task] += score;
    else
        scores[student][task] = score;
}

int GradeBook::get_score(string student, string task)
{
    map<string, int>::iterator it = scores[student].find(task);
    if (it != scores[student].end())
        return scores[student][task];
	return -1;
}
