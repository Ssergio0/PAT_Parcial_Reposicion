#include "Ejercicio01.h"

Node<int>* Ejercicio01::addTwoNumbers(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2) {
    Node<int>* dummyHead = new Node<int>(); // Nodo inicial para el resultado
    Node<int>* current = dummyHead;
    int carry = 0; // Para manejar el acarreo

    // Mientras haya nodos para procesar o haya un acarreo
    while (l1 != nullptr || l2 != nullptr || carry > 0) {
        int sum = carry; // Empezar con el valor del acarreo

        // Sumar los valores de los nodos si existen
        if (l1 != nullptr) {
            sum += l1->value;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->value;
            l2 = l2->next;
        }

        carry = sum / 10; 
        sum %= 10; // El dígito a almacenar en el nodo es el residuo de la suma dividida entre 10

        // Crear el nuevo nodo con el dígito y añadirlo al resultado
        Node<int>* newNode = new Node<int>();
        newNode->value = sum;
        current->next = newNode;
        current = newNode;
    }

    Node<int>* result = dummyHead->next; // El resultado inicia en el siguiente nodo del dummyHead
    delete dummyHead; // Eliminar el nodo dummy ya que no es parte del resultado
    return result; // Devolver el nodo cabeza del resultado
}
