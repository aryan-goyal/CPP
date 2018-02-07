//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <cstddef>
#include <float.h>
#include <math.h>
#include <limits.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

//////////////////////////////////////////////////////////////
//
// local #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

#endif

//////////////////////////////////////////////////////////////
//
// struct definitions 
//
#ifndef MARMOSET_TESTING

enum COURSE {
    CHE102, MATH115, MATH117, ECE105, ECE150, ECE190, Null
};

struct Assignment {
    COURSE course; // CHE102, MATH117, etc.
    int assnNum; // Assignment Number
    int dueMonth; // Month due (1-12)
    int dueDay; // Day due (1-31)
    char *description; // Assignment description
};

struct HomeworkQueue {
    Assignment *assn;
    HomeworkQueue *nextInQueue;
};

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
//

bool enqueue(HomeworkQueue *&queue, const Assignment &assignment);

const Assignment *dequeue(HomeworkQueue *&queue);

int daysTillDue(const HomeworkQueue *q, const COURSE course);

const Assignment *dueIn(const HomeworkQueue *q, const int numDays);

//////////////////////////////////////////////////////////////
//
// Function definitions. PLEASE USE HELPER FUNCTIONS
//

bool enqueue(HomeworkQueue *&queue, const Assignment &assignment) {
    //error checks
    if (assignment.dueMonth <= 0 || assignment.dueMonth > 12 || assignment.dueDay > 31 || assignment.dueDay <= 0) {
        return false;
    }

    if (assignment.description == NULL) {
        return false;
    }

    //more error checks for months with excess days, omg why is this a thing
    if (assignment.dueMonth == 2) {
        if (assignment.dueDay > 28) {
            return false;
        }
    }
    if (assignment.dueMonth == 4) {
        if (assignment.dueDay > 30) {
            return false;
        }
    }
    if (assignment.dueMonth == 6) {
        if (assignment.dueDay > 30) {
            return false;
        }
    }
    if (assignment.dueMonth == 9) {
        if (assignment.dueDay > 30) {
            return false;
        }
    }
    if (assignment.dueMonth == 11) {
        if (assignment.dueDay > 30) {
            return false;
        }
    }


    //make another assignment which is not const
    Assignment *newAss = new Assignment;
    newAss->course = assignment.course;
    newAss->dueMonth = assignment.dueMonth;
    newAss->dueDay = assignment.dueDay;
    newAss->assnNum = assignment.assnNum;
    newAss->description = assignment.description;

    //create new node
    HomeworkQueue *newQ = new HomeworkQueue;
    newQ->assn = newAss;
    newQ->nextInQueue = NULL;

    //if the head's assignment is empty, insert before head
    if (queue->assn == NULL) {
        newQ->nextInQueue = queue;
        queue = newQ;
        return true;
    }

    //if assignment is due first, make it the head
    if (newQ->assn->dueMonth <= queue->assn->dueMonth) {
        if (newQ->assn->dueMonth == queue->assn->dueMonth) {
            if ((newQ->assn->dueDay) == (queue->assn->dueDay)) {
                //newQ gets added behind queue, then update head
                newQ->nextInQueue = queue->nextInQueue;
                queue->nextInQueue = newQ;
                return true;
            } else if ((newQ->assn->dueDay) < (queue->assn->dueDay)) {
                //newQ gets added in front of queue, then update head
                newQ->nextInQueue = queue;
                queue = newQ;
                return true;
            } else {
                queue->nextInQueue = newQ;
                return true;
            }
        }
        //if it falls into none of them, then add it to the front of queue, then update head
        newQ->nextInQueue = queue;
        queue = newQ;
        return true;
    }

    //if adding in between queues, after the head
    HomeworkQueue *front = new HomeworkQueue;
    HomeworkQueue *back = new HomeworkQueue;
    front = queue->nextInQueue;
    back = queue;

    while (front->nextInQueue != NULL) {
        if ((front->assn->dueMonth) <= (newQ->assn->dueMonth)) {
            if ((front->assn->dueMonth) == (newQ->assn->dueMonth)) {
                if ((front->assn->dueDay) == (newQ->assn->dueDay)) {
                    //if month and date are equal
                    newQ->nextInQueue = front->nextInQueue;
                    front->nextInQueue = newQ;
                    return true;
                } else if ((front->assn->dueDay) > (newQ->assn->dueDay)) {
                    //if the assignment is due later, back point to newQ and newQ points to front
                    newQ->nextInQueue = front;
                    back->nextInQueue = newQ;
                    return true;
                } else {
                    //if all else, move forward through, front and back are next in queue
                    front = front->nextInQueue;
                    back = back->nextInQueue;
                }
            }
            //move forward through
            front = front->nextInQueue;
            back = back->nextInQueue;
        }
    }

    //if it is the last node, it will not go into any of the if loops (/🅱\)
    newQ->nextInQueue = front;
    back->nextInQueue = newQ;
    return true;
}

const Assignment *dequeue(HomeworkQueue *&queue) {
    //error checks
    if (queue == NULL) {
        return NULL;
    }

    HomeworkQueue *newQ2 = queue;

    if (queue->nextInQueue == NULL) {
        queue = NULL;
    } else {
        //move pointer up
        queue = queue->nextInQueue;
    }

    return newQ2->assn;
}

int daysTillDue(const HomeworkQueue *q, const COURSE course) {
    if (q->assn == NULL || q == NULL) {
        return INT_MAX;
    }

    //time difference algorithm modified from http://www.cplusplus.com/reference/ctime/difftime/

    if (q->assn->course == course) {
        //get current date
        time_t iniT = time(0); //get current time
        struct tm *iniT2 = localtime(&iniT);
        iniT2->tm_year = 0;
        iniT2->tm_mon = iniT2->tm_mon + 1;
        time_t currentDate = mktime(&*iniT2);

        //Convert the due date so you can compare the two different values
        struct tm dueT = {0, 0, 0, q->assn->dueDay, q->assn->dueMonth, 0};
        time_t dueD = mktime(&dueT);

        //calc the daysTillDue
        int difference = (int) difftime(dueD, currentDate) / 86400;

        return abs(difference);
    };

    return INT_MAX;
}

const Assignment *dueIn(const HomeworkQueue *q, const int numDays) {
    return NULL;
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
//

#ifndef MARMOSET_TESTING

int main(const int argc, const char *const argv[]) {
    // Some test driver code here ....
    std::cout << std::endl << "Implement some more appropriate tests in main()" << std::endl << std::endl;

    HomeworkQueue *p_queue = new HomeworkQueue;
    p_queue->nextInQueue = NULL;
    p_queue->assn = NULL;

    char sampleDescription[] = "Sequential Execution";
    Assignment assn1 =
            {
                    .course = ECE150,
                    .assnNum = 0,
                    .dueMonth = 9,
                    .dueDay = 15,
                    .description = sampleDescription
            };

    bool enqueueSuccess = enqueue(p_queue, assn1);

    if (enqueueSuccess) {
        std::cout << "assn1 enqueued successfully" << std::endl << std::endl;

    } else {
        std::cout << "enqueue() failed" << std::endl << std::endl;
    }

    const Assignment *p_firstAssignmentInQueue = dequeue(p_queue);

    if (p_firstAssignmentInQueue) {
        std::cout << "Dequeue successful..." << std::endl;
        std::cout << "Course: " << p_firstAssignmentInQueue->course << std::endl;
        std::cout << "Assignment #: " << p_firstAssignmentInQueue->assnNum << std::endl;
        std::cout << "Day due: " << p_firstAssignmentInQueue->dueDay << std::endl;
        std::cout << "Month due: " << p_firstAssignmentInQueue->dueMonth << std::endl;
        std::cout << "Description: " << p_firstAssignmentInQueue->description << std::endl;
    } else {
        std::cout << "dequeue() failed" << std::endl;
    }

    delete p_queue;

    return 0;
}

#endif
