#include <iostream>
#include "Message.h"

#ifndef MESSAGE_H

#define MESSAGE_H
class Node {
    friend class Message;
    public:
        Node *get_next(); //Returns the pointer to the next node.
        std::string get_fragment(); //Returns the string representing the fragment stored in this packet.
        Node( unsigned int id, std::string frag ); // This is the constructor
    private:
        unsigned int identifier; //Stores the packet identifier.
        std::string fragment; //Stores the packet message that corresponds to one string.
        Node *p_next; //A pointer to the next node in the linked list of type Node.
};
class Message {
    public:
        Message();
        //This is the default constructor. It will set the head to the null pointer.
        
        ~Message();
        //This is the destructor. We must ensure that the dynamically allocated nodes are deallocated properly.

        void insert( unsigned int id, std::string fragment);
        //Inserts a node in the linked list that contains the packet information provided as parameters. 

        void print_message();
        //Prints to the console output stream the stored message as described above.

    private:
        Node *head; //A pointer to the first packet of the message.

};
#endif

#ifndef MARMOSET_TESTING
int main();
int main()
{
    Message first;
    int ide;
    std::string input;
    for (;;)
    {
        std:: cin >> ide;
        if (ide == -1)
            {
             first.print_message(); //
            }
             if (ide == -2)
            {
                break;
            }
            else if (ide >= 0)
            {
                std::cin >> input;
                first.insert(ide, input);

            }
        
    }

    return 0; 
}

#endif


Node *Node::get_next()
{
    return p_next;
}

std::string Node::get_fragment()
{
    return fragment;

}
 Node::Node(unsigned int id, std::string frag)
 {
    identifier = id;
    fragment = frag;
 }

 Message::Message()
 {
    head = nullptr;
 }

 Message::~Message()
 {
    Node*one;
    while (head != nullptr)
    {
        one = head;
        head = head -> p_next;
        delete one;
    } 


 }

void Message::insert(unsigned int id, std::string fragment)
{

Node *one;
one = new Node(id, fragment);
Node *two;
Node *three;
two = head;
 if (head == nullptr)
 {
    one -> p_next = nullptr;
    head = one;
 }
 else if (two -> identifier > id)
 {
    one -> p_next =  head;
    head = one;
 }
 else
 {
    do
    {
        three = two;
        two = two -> p_next;
        if( two == nullptr)
        {
            break;
        }

    }while (two -> identifier < id);

        one -> p_next = three -> p_next;
        three -> p_next = one;
    
 }
}
void Message::print_message()
{
    Node *one;
    one = head;

    int num{0};
    
    for (;;)
    {
        if (one == nullptr)
        {
            std::cout << " ??? " << std::endl;
            break;
        }

         if (one -> identifier == num)
         {
            if (one -> fragment == "EOT")
            {
                std::cout << std::endl;
                break;
            }

            std::cout << one -> get_fragment() << " ";
            one = one -> p_next;
         } 

         else
        {
            std::cout << "... ";
        }
  
    num++;

    } 

    

}