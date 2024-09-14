#include <iostream>
#include <cstdlib>
using namespace std;
class Term
{
public:
    int coefficient;
    int index;
    Term *Next;
    Term(int coefficient, int index)
    {
        this->coefficient = coefficient;
        this->index = index;
        this->Next = nullptr;
    }
};
class Polynomial
{
public:
    Term *head;
    Polynomial()
    {
        this->head = nullptr;
    }
    void InsertAtHead(int coefficient, int index)
    {
        Term *new_node = new Term(coefficient, index);
        new_node->Next = head;
        head = new_node;
    }
    void InsertAtTail(int coefficient, int index)
    {
        Term *new_node = new Term(coefficient, index);
        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        Term *temp = head;
        while (temp->Next != nullptr)
        {
            temp = temp->Next;
        }
        temp->Next = new_node;
    }
    void Insert(int coefficient, int power, int index)
    {
        if (index == 0)
        {
            InsertAtHead(coefficient, power);
            return;
        }
        Term *temp = head;
        int counter = 0;
        Term *new_node = new Term(coefficient, power);
        while (temp != nullptr and counter < index)
        {
            temp = temp->Next;
            counter++;
        }
        if (temp = nullptr)
        {
            cout << "Index out of bound" << endl;
            delete new_node;
            return;
        }
        new_node->Next = temp->Next;
        temp->Next = new_node;
    }
    void DeleteFromHead()
    {
        if (head == nullptr)
        {
            cout << "list is alsready empty" << endl;
            return;
        }
        Term *temp = head;
        head = head->Next;
        delete temp;
    }
    void DeleteFromTail()
    {
        if (head == nullptr)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        if (head->Next == nullptr)
        {
            DeleteFromHead();
            return;
        }
        Term *secondlastTerm = head;
        while (secondlastTerm->Next->Next != nullptr)
        {
            secondlastTerm = secondlastTerm->Next;
        }
        Term *lastTerm = secondlastTerm->Next;
        secondlastTerm->Next = nullptr;
        delete lastTerm;
    }
    void Delete(int index)
    {
        if (index < 0)
        {
            cout << "invalid indexing" << endl;
            return;
        }
        if (index == 0)
        {
            DeleteFromHead();
            return;
        }
        int counter = 0;
        Term *temp = head;
        while (temp != nullptr and counter < index)
        {
            temp = temp->Next;
            counter++;
        }
        if (temp == nullptr)
        {
            cout << "index out of bound" << endl;
            return;
        }
        Term *toDelete = temp->Next;
        temp->Next = temp->Next->Next;
        delete toDelete;
    }

    void Display()
    {

        if (head == nullptr)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        Term *temp = head;
        while (temp->Next != nullptr)
        {

            cout << temp->coefficient << " * ( x ^ " << temp->index << " ) + ";
            temp = temp->Next;
        }
        cout << temp->coefficient << " * ( x ^ " << temp->index << " ) " << endl;
    }
    void CombineLikeTerms()
    {
        if (head == nullptr)
            return;

        Term *current = head;

        while (current != nullptr)
        {
            Term *runner = current;

            while (runner->Next != nullptr)
            {
                if (runner->Next->index == current->index)
                {
                    current->coefficient += runner->Next->coefficient;
                    Term *temp = runner->Next;
                    runner->Next = runner->Next->Next;
                    delete temp;
                }
                else
                {
                    runner = runner->Next;
                }
            }
            current = current->Next;
        }
    }

    Polynomial operator+(const Polynomial &other) const
    {
        Polynomial result;

        Term *temp = head;
        Term *otherTemp = other.head;

        Term *resultTail = nullptr;
        while (temp != nullptr && otherTemp != nullptr)
        {
            if (temp->index == otherTemp->index)
            {
                result.InsertAtTail(temp->coefficient + otherTemp->coefficient, temp->index);
                temp = temp->Next;
                otherTemp = otherTemp->Next;
            }
            else if (temp->index > otherTemp->index)
            {
                result.InsertAtTail(temp->coefficient, temp->index);
                temp = temp->Next;
            }
            else
            {
                result.InsertAtTail(otherTemp->coefficient, otherTemp->index);
                otherTemp = otherTemp->Next;
            }
        }
        while (temp != nullptr)
        {
            result.InsertAtTail(temp->coefficient, temp->index);
            temp = temp->Next;
            while (otherTemp != nullptr)
            {
                result.InsertAtTail(otherTemp->coefficient, otherTemp->index);
                otherTemp = otherTemp->Next;
            }
        }
        return result;
    }
    Polynomial operator-(const Polynomial &other) const
    {
        Polynomial result;

        Term *temp = head;
        Term *otherTemp = other.head;

        Term *resultTail = nullptr;
        while (temp != nullptr && otherTemp != nullptr)
        {
            if (temp->index == otherTemp->index)
            {
                result.InsertAtTail(temp->coefficient - otherTemp->coefficient, temp->index);
                temp = temp->Next;
                otherTemp = otherTemp->Next;
            }
            else if (temp->index > otherTemp->index)
            {
                result.InsertAtTail(temp->coefficient, temp->index);
                temp = temp->Next;
            }
            else
            {
                result.InsertAtTail(-otherTemp->coefficient, otherTemp->index);
                otherTemp = otherTemp->Next;
            }
        }
        while (temp != nullptr)
        {
            result.InsertAtTail(temp->coefficient, temp->index);
            temp = temp->Next;
            while (otherTemp != nullptr)
            {
                result.InsertAtTail(otherTemp->coefficient, otherTemp->index);
                otherTemp = otherTemp->Next;
            }
        }
        return result;
    }

    Polynomial operator*(const Polynomial &other) const
    {
        Polynomial result;

        Term *temp = head;
        Term *otherTemp = other.head;

        Term *resultTail = nullptr;
        while (temp != nullptr)
        {

            while (otherTemp != nullptr)
            {
                result.InsertAtTail(otherTemp->coefficient * temp->coefficient, otherTemp->index + temp->index);
                otherTemp = otherTemp->Next;
            }
            temp = temp->Next;
            otherTemp = other.head;
        }
        result.CombineLikeTerms();
        return result;
    }
};
int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("../../input.txt", "r", stdin);
//     freopen("../../output.txt", "w", stdout);
// #endif
    Polynomial A1;
    A1.InsertAtTail(3, 2);
    A1.InsertAtTail(4, 1);
    A1.InsertAtTail(5, 0);
    cout << "Polynomial A1: ";
    A1.Display();

    Polynomial B1;
    B1.InsertAtTail(2, 2);
    B1.InsertAtTail(1, 1);
    B1.InsertAtTail(3, 0);
    cout << "Polynomial B1: ";
    B1.Display();

    Polynomial sum = A1 + B1;
    cout << "Result of A1 + B1: ";
    sum.Display();

    Polynomial difference = A1 - B1;
    cout << "Result of A1 - B1: ";
    difference.Display();

    Polynomial product = A1 * B1;
    cout << "Result of A1 * B1: ";
    product.Display();

    return EXIT_SUCCESS;
}