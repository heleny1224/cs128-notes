template <typename T>
void DoublyLinkedList<T>::SpliceAfter(unsigned int pos, DoublyLinkedList<T>& other) {
if(other.head_ == nullptr) {
  return;
}
  if(head_ == nullptr) {
    head_ = other.head_;
    tail_ = other.tail_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
    return;
  }
  if(pos == 0) {
    head_->prev = other.tail_;
    other.tail_->next = head_;
    head_ = other.head_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
    return;
  }
  unsigned int count = 0;
  Node<T>* current = head_;
  while(current != nullptr && count != pos) {
    current = current->next;
    count++;
  }
if (current == nullptr && count == pos) {
    tail_->next = other.head_;
  other.head_->prev = tail_;
  tail_ = other.tail_;
} else if(current != nullptr) {
    current->prev->next = other.head_;
    other.head_->prev = current->prev;
    other.tail_->next = current;
    current->prev = other.tail_;
  }
  other.head_ = nullptr;
    other.tail_ = nullptr;
}


template <typename T>
void SinglyLinkedList<T>::AbsorbSorted(singlyLInkedList<T>& other) {
  if(other.head_ == nullptr) {
    return;
  }
  if(head_ == nullptr) {
    head_ = other.head_;
    tail_ = other.tail_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
    return;
  }
  Node<T>* add = other.head_;
  Node<T>* current = head_;
  Node<T>* prev = nullptr;
  while(current != nullptr && add != nullptr) {
    if(add->data < current->data){
      Node<T>* nextadd = add->next;
    add->next = current;
      if(prev == nullptr){
        head_ = add;
      } else {
       prev->next = add; 
      }
    prev = add;
      add = nextadd;
    } else {
      prev = current;
      current = current->next;
    }
  }
  if(add != nullptr) {
      tail_->next = add;
      tail_ = other.tail_;
    }
  
  other.head_ = nullptr;
  other.tail_= nullptr;
}

template <typename T>
void DoublyLinkedList<T>::RotateLeft(unsigned int k) {
  if(head_ == nullptr || k == 0) {
    return;
  }
  unsigned int size = 0;
  Node<T>* it = head_;
  while(it != nullptr) {
    size++;
    it = it->next;
  }
  if (k > size) {
    k = k % size;
  }
  
  unsigned int count = 0;
  Node<T>* current = head_;
  while(current != nullptr && count != k) {
    current = current->next;
    count++;
  }
  if(current == nullptr && count == k) {
    return;
  } else {
    tail_->next = head_;
    head_->prev = tail_;
    tail_ = current->prev;
    current->prev = nullptr;
    head_ = current;
  }
}

template <typename T>
void SinglyLinkedList<T>::MoveGreater(
    T threshold, SinglyLinkedList<T>& other) {
  Node<T>* current = head_;
  Node<T>* prev = nullptr;
  while(current != nullptr) {
    Node<T>* next = current->next;
    if(current->data > threshold) {
      if(other.head_ == nullptr){
        other.head_ = current;
        other.tail_ = current;
      } else {
      other.tail_ ->next = current;
      other.tail_ = current;
      }
      if(current == head_) {
        head_ = next;
      } else {
        prev->next = next;
      }
      if(current == tail_) {
        tail_ = prev;
      }
      current->next = nullptr;
    } else {
      prev = current;
    }
    current = next;
    }
  }
