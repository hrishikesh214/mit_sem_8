/**
 * @file lab1.c
 * @author Hrishikesh Vaze ()
 * @brief bully algorithm implementation
 * @date 2023-01-25
 *
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    int priority;
    int isActive;
} Node;

int bullyAlgorithm(Node *nodes, int n, int invokerIndex)
{
    int maxPriority = nodes[invokerIndex].priority;
    int maxPriorityIndex = invokerIndex;

    for (int i = invokerIndex + 1; i < n; i++)
    {
        if (nodes[i].priority > maxPriority && nodes[i].isActive)
        {
            maxPriority = nodes[i].priority;
            maxPriorityIndex = i;
        }
    }

    for (int i = 0; i <= invokerIndex; i++)
    {
        if (nodes[i].priority > maxPriority && nodes[i].isActive)
        {
            maxPriority = nodes[i].priority;
            maxPriorityIndex = i;
        }
    }

    return maxPriorityIndex;
}

int main()
{
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    Node *nodes = (Node *)malloc(n * sizeof(Node));

    for (int i = 0; i < n; i++)
    {
        printf("Enter the priority of node %d: ", i + 1);
        scanf("%d", &nodes[i].priority);
        printf("Enter the status of node %d: ", i + 1);
        scanf("%d", &nodes[i].isActive);
    }

    int invokerIndex;
    printf("Enter the num id of the node that invokes the election: ");
    scanf("%d", &invokerIndex);

    int coordinatorIndex = bullyAlgorithm(nodes, n, invokerIndex - 1);

    printf("The new coordinator is node %d", coordinatorIndex + 1);

    return 0;
}