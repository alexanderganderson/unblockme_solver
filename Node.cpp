//
//  Node.cpp
//  unblockme_solver
//
//  Created by Alexander G Anderson on 12/16/13.
//  Copyright (c) 2013 Alexander G Anderson. All rights reserved.
//

#include "Node.h"

/*Node::Node(CBoard c) {
    vector<int> parents;
    vector<int> children;
    CBoard cb = c;
}
*/

Node::Node() {
    vector<int> parents;
    vector<int> children;
    CBoard cb;
}

void Node::print() {
    cout << "The parents are: ";
    for (vector<int>::iterator i = parents.begin(); i != parents.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl << "The children are: ";
    for (vector<int>::iterator i = children.begin(); i != children.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
    cb.print();
}