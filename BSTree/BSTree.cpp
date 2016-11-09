#include "BSTree.h"

template<class T>
Node<T>* BTree<T>::copy(Node<T>* other){
	if (other == nullptr){
		return nullptr;
	}
	Node<T>* copyNode = new Node<T>(other->data);
	copyNode->left = copy(other->left);
	copyNode->right = copy(other->right);
	return newNode;
}

template<class T>
BTree<T>::BTree(const BTree<T>& other){
	root = copy(other.root);
}

template<class T>
BTree<T>&::BTree<T>::operator=(const BTree<T>& other){
	if (this != &other){
		delete_tree(root);
		Node *root = copy(other.root);
	}
	return *this;
}

template<class T>
BTree<T>::BTree() :root(nullptr){};

template<class T>
BTree<T>::~BTree(){
	delete_tree(root);
}

template<class T>
void BTree<T>::delete_tree(Node<T>* node){
	if (node == nullptr){
		return;
	}
	delete_tree(node->left);
	delete_tree(node->right);
	delete node;
}

template<class T>
bool BTree<T>::add_node(const int elem, Node<T>*& node){
	if (node == nullptr){
		node = new Node<T>(elem);
		return true;
	}
	else{
		if (elem > node->data){
			return add_node(elem, node->right);
		}
		if (elem < node->data){
			return add_node(elem, node->left);
		}
		else{
			return false;
		}
	}
}

template<class T>
bool BTree<T>::add(const int elem){
	return add_node(elem, root);
}

template<class T>
Node<T>*& BTree<T>::find(const int elem, Node<T>*& node){
	if (node == nullptr || node->data == elem){
		return node;
	}
	else{
		if (elem < node->data){
			return find(elem, node->left);
		}
		return find(elem, node->right);
	}
}

template<class T>
bool BTree<T>::remove(const int elem){
	Node<T>*& remove_this = find(elem, root);
	if (remove_this == nullptr){
		return false;
	}
	Node<T>* to_delete = remove_this;
	Node<T>* replacement = remove_this->left;
	if (replacement == nullptr){
		replacement = remove_this->right;
	}
	else{
		Node<T>* rightmost = remove_this->left;
		while (rightmost->right != nullptr){
			rightmost = rightmost->right;
		}
		rightmost->right = remove_this->right;	
	}
	remove_this = replacement;
	delete to_delete;
	return true;
}

template<class T>
bool BTree<T>::contains(const int elem){
	return find(elem, root) != nullptr;
}

template<class T>
void BTree<T>::preorder(Node<T>* node,std::vector<T>& result) const{
	if (node == nullptr){
		return;
	}
	result.push_back(node->data);
	preorder(node->left, result);
	preorder(node->right, result);
}

template<class T>
std::vector<T> BTree<T>::preorderTraversal() const{
	std::vector<T> result;
	preorder(root, result);
	return result;
}

template<class T>
void BTree<T>::inorder(Node<T>* node, std::vector<T>& result) const{
	if (node == nullptr){
		return;
	}
	inorder(node->left, result);
	result.push_back(node->data);
	inorder(node->right, result);
}

template<class T>
std::vector<T> BTree<T>::inorderTraversal() const{
	std::vector<T> result;
	inorder(root, result);
	return result;
}

template<class T>
void BTree<T>::postorder(Node<T>* node, std::vector<T>& result) const{
	if (node == nullptr){
		return;
	}
	postorder(node->left, result);
	postorder(node->right, result);
	result.push_back(node->data);
}

template<class T>
std::vector<T> BTree<T>::postorderTraversal() const{
	std::vector<T> result;
	inorder(root, result);
	return result;
}
int main(){
	return 0;
}