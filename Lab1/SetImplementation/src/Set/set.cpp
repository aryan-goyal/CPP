#include "tuple.h"
#include "set.h"
#include "invariant.h"
#include <iostream>
#include <limits.h>   // needed for INT_MIN

// Set up an error set to be returned as necessary
const Set emptySet(0,(int*)0);
const Set errorSet(-1,(int*)0);

bool Set::isEmpty() const {
  return _numElements == 0;
}

bool Set::isError() const {
  return _numElements == -1;
}

int Set::cardinality() const {
  if (_numElements < 0){
    return INT_MIN;
  }
  else {
      return _numElements;
  }
}

Set Set::union_(const Set& s) const {
  if(_numElements == 0){
    return s;
  }
  if(_numElements < 0 || s.isError()){
    return errorSet;
  }
  if(s.isEmpty()){
    return Set(_tupleArraySize, _pTuples);
  }
  if(_numElements == 0 && s.isEmpty()){
    return emptySet;
  }

  int size = _numElements + s.cardinality();
  Tuple newArray[size];
  for(int x = 0; x < size; x++){
    if (x < _numElements){
        newArray[x] = _pTuples[x];
    }
    else {
      newArray[x] = s._pTuples[x - _numElements];
    }
  }
  return Set(size, newArray);
}

Set Set::intersection(const Set& s) const {
  Tuple newArray[_numElements];
  int size = 0;
  for(int x = 0; x <_numElements; x++){
    for(int y = 0; y <s._numElements; y++){
      if(_pTuples[x] == s._pTuples[y]){
        newArray[x] = _pTuples[x];
        size++;
      }
    }
  }
  return Set(size, newArray);
}

Set Set::difference(const Set& s) const {
  //error checking
  if(_numElements == 0){
    return emptySet;
  }
  if(_numElements < 0 || s.isError()){
    return errorSet;
  }

  //main function for difference
  Tuple newArray[_numElements];
  bool on = true;
  int size = 0;
  for(int x = 0; x <_numElements; x++){
    for(int y = 0; y <s._numElements; y++){
      if(_pTuples[x] == s._pTuples[y]){
        on = false;
      }
    }
    if(on){
      newArray[size] = _pTuples[x];
      size++;
    }
    on = true;
  }
  return Set(size, newArray);
}

Set Set::select(predicate* p) const {
  Tuple newArray[_numElements];
  int size = 0;
  for(int x = 0; x <_numElements; x++){
    if(p(_pTuples[x])){
      newArray[size] = _pTuples[x];
      size++;
    }
  }
  return Set(size, newArray);
}

Set Set::project(const int numItems, const int items[]) const {
  if(isError()) return errorSet;
  Tuple newArray[_numElements];
  for(int x = 0; x <_numElements; x++){
    int array[numItems];
    for(int y = 0; y < numItems; y++){
      array[y] = _pTuples[x](items[y]);
    }
    newArray[x] = Tuple(numItems, array);
  }
  return Set(_numElements, newArray);
}

Set Set::cartesian(const Set& s) const {
  Tuple newArray[_numElements*s._numElements];
  int size = 0;
  for(int x = 0; x <_numElements; x++){
    for(int y = 0; y <s._numElements; y ++){
      Tuple temporary = s._pTuples[y] + _pTuples[x];
      newArray[size] = temporary;
      size++;
    }
  }
  return Set(size, newArray);
}

Set Set::operator()(const int item) const {
  return emptySet;
}

void Set::operator=(const Set& s) {
  _pTuples = new Tuple[s._numElements];

  for(int x = 0; x < s._numElements; x++){
    _pTuples[x] = s._pTuples[x];
  }
}

Set::Set() {
  _tupleArraySize = 0;
  _numElements = 0;
  _pTuples = NULL;
}

Set::Set(const Set& s) {
  _pTuples = s._pTuples;
  _numElements = s._numElements;
  _tupleArraySize = s._tupleArraySize;
}

Set::Set(const int numElements, const int data[]) {
//error check
  if(numElements ==0){
    _tupleArraySize = 0;
    _numElements = 0;
    _pTuples = NULL;
    return;
  }
  if(numElements < 0){
    _tupleArraySize = -1;
    _numElements = 0;
    _pTuples = NULL;
    return;
  }

//Check for duplicates
  _tupleArraySize = numElements;
  _numElements = numElements;
  int uni = 0;
  int newSet[numElements];
  bool on = true;
  for(int x = 0; x<numElements; x++){
    for(int y = x+1; y<numElements; y++){
      if(data[x]==data[y]){
        on = false;
      }
    }
    if(on){
      newSet[uni] = data[x];
      ++uni;
    }
    on = true;
  }
  _pTuples = new Tuple[uni];
  for(int x = 0; x <uni; x++){
    _pTuples[x] = Tuple(newSet[x]);
  }
  _numElements = uni;
  _tupleArraySize = uni;
}

Set::Set(const int numElements, const Tuple tuples[]) {
  if(numElements ==0){
    _tupleArraySize = 0;
    _numElements = 0;
    _pTuples = NULL;
    return;
  }
  if(numElements < 0){
    _tupleArraySize = -1;
    _numElements = 0;
    _pTuples = NULL;
    return;
  }

  //Check for duplicates
  _tupleArraySize = numElements;
  _numElements = numElements;
  int uni = 0;
  Tuple nT[numElements];
  bool on = true;
  for(int x = 0; x<numElements; x++){
    for(int y = x+1; y<numElements; y++){
      if(tuples[x]==tuples[y]){
        on = false;
      }
    }
    if(on){
      nT[uni] = Tuple(tuples[x]);
      ++uni;
    }
    on = true;
  }
  _pTuples = new Tuple[uni];
  for(int x = 0; x <uni; x++){
    _pTuples[x] = Tuple(nT[x]);
  }
  _numElements = uni;
  _tupleArraySize = uni;
}

Set::~Set() {
  _numElements = -10;
  _tupleArraySize = 0;
  _pTuples = NULL;
}

std::ostream& operator<<(std::ostream& os, const Set& s) {
  if(s.isEmpty())
  {
    os << "{}";
    return os;
  }
  else if(s.isError()){
    os << "{ERRORSET}";
    return os;
  }

  os << "{";
  for(int x = 0; x < s._tupleArraySize; x++){
    if(x == (s._tupleArraySize - 1)){
      os << s._pTuples[x];
    }
    else{
      os << s._pTuples[x];
      os << ",";
    }
  }
  os << "}";

  return os;
}
