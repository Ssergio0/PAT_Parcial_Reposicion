#include "Ejercicio02.h"

// Funci�n auxiliar para revertir una parte de la lista.
Node<char>* reversePartial(Node<char>* start, Node<char>* end) {
    Node<char>* prev = end;
    while (start != end) {
        Node<char>* temp = start->next;
        start->next = prev;
        prev = start;
        start = temp;
    }
    return prev;
}

// Funci�n para revertir nodos en grupos de k.
Node<char>* Ejercicio02::reverseKGroup(Node<char>* head, int k) {
    Node<char>* current = head;
    Node<char>* ktail = nullptr;
    Node<char>* new_head = nullptr;

    // Comienza el proceso de inversi�n de k nodos.
    while (current) {
        int count = 0;
        current = head;

        // Comprueba si hay suficientes nodos para revertir.
        while (count < k && current) {
            current = current->next;
            count++;
        }

        // Si hay suficientes nodos, procede con la reversi�n.
        if (count == k) {
            // Revertir k nodos.
            Node<char>* reversed_head = reversePartial(head, current);

            // Si la nueva cabeza no ha sido definida, establecerla ahora.
            if (!new_head) {
                new_head = reversed_head;
            }

            // Si tenemos un ktail, entonces es la cola del grupo previo; 
            // conectamos directamente al inicio del grupo revertido.
            if (ktail) {
                ktail->next = reversed_head;
            }

            // Despu�s de la reversi�n, la cabeza se convierte en la cola del grupo.
            ktail = head;
            head = current;
        }
    }

    // Si hay nodos que no han sido revertidos al final (nodos restantes < k),
    // su orden permanece igual, por lo que solo conectamos la cola del �ltimo grupo revertido con el primer nodo de los restantes.
    if (ktail) {
        ktail->next = head;
    }

    // Si la nueva cabeza no ha sido establecida, significa que no invertimos ning�n nodo 
    // (k > longitud de la lista), as� que retornamos la cabeza original.
    return new_head ? new_head : head;
}
