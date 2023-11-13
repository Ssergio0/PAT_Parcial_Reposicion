#include "Ejercicio03.h"

Node<int>* Ejercicio03::detectCycle(Node<int>* head) {
    if (!head || !head->next) {
        return nullptr; // No hay suficientes nodos para formar un ciclo.
    }

    Node<int>* slow = head, * fast = head;

    // Primero determinamos si hay un ciclo.
    do {
        if (!fast || !fast->next) return nullptr;
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    // Hay un ciclo, ahora encontramos el nodo de entrada al ciclo.
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Tanto slow como fast están ahora en el nodo de entrada al ciclo.
    return slow;
}
