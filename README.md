# Sequence

Custom container equipped with 11 algorithms tailored to optimize data access and manipulation

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)


## Introduction

Welcome to the **Sequence** repository! A "Sequence" is a type of container, much like a vector, except that it has been equipped with many algorithms that make it easy to access and manipulate data! 

## Features

There are 11 algorithms
- empty(): return true if the sequence is empty, otherwise false
- size(): return the number of items in the sequence
- insert(position, value): insert value at a specified position
- insert(value): insert value such that the values in the Sequence are in increasing order
- erase(position): erase the value at a specified position
- remove(value): erase all items from the Sequence that are equal to the specified value
- get(position, value): copy the value at specified position into value
- find(value): return the position of the first instance of value
- swap(otherSequence): exchange the contents of this sequence with the other one
- subsequence(Sequence1, Sequence2): returns true if Sequence2 is a consecutive subsequence of Sequence1
- concatReverse(Sequence1, Sequence2, resultSequence): concatenates and reverses Sequence1 and Sequence2, putting the resulting Sequence into resultSequence


## Installation

1. Clone the repository: `git clone https://github.com/joshfendi/Sequence`
2. Navigate to the project directory: `cd Sequence`
3. Install dependencies: `npm install`

## Usage

Once you have the project opened, navigate to the file main.cpp. This file shows test cases that demonstrate the capabilities and usages of the Sequence container

You can write your own test cases to play around with the Sequence container. All that is left to do is open up a new terminal and run the code!
