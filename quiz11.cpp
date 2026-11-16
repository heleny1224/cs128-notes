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
  while(current != nullptr || count != pos) {
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
