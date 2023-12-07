# School Hostel Allocation System

## Overview

The Sorting Hat Hostel Allocation System is a versatile C++ program designed to manage the allocation of students to different hostels, taking into account their class and food preferences. Inspired by the Sorting Hat from the magical world, this system ensures a fair and balanced distribution of students, providing a clear and concise solution to hostel allocation challenges.

## Features

### 1. Dynamic Allocation

The system dynamically allocates students to hostels, ensuring an optimal distribution within the specified hostel capacity. It prioritizes efficient space utilization while maintaining fairness in the allocation process.

### 2. Balanced Categories

Students are categorized into four main groups based on their class (A or B) and food preference (Vegetarian or Non-Vegetarian):

- **BV (B Vegetarian)**
- **AV (A Vegetarian)**
- **BNV (B Non-Vegetarian)**
- **ANV (A Non-Vegetarian)**

Additionally, students who could not be accommodated within the capacity are listed under **NA (Not Assigned)**, providing transparency in the allocation process.

### 3. User-Friendly Input

The program allows easy and flexible input through the standard input (stdin). Users can either input data manually or use input redirection from a file, making it adaptable to various scenarios and data sources.

## Usage

### Input Format

1. The first line: "init <capacity>", where `<capacity>` is the total hostel capacity.
2. Subsequent lines: "<operation> <rollNo> <classId> <foodPreference>".
   - `<operation>` is either "fin" to finish input or "reg" to register a student.

### Example Input

```plaintext
init 12
reg 1 B V
reg 2 A V
reg 3 A V
reg 4 B NV
reg 5 B V
reg 6 A NV
reg 7 A V
reg 8 A NV
reg 9 B NV
reg 10 B V
reg 11 A NV
reg 12 B NV
reg 13 A NV
fin

### Example Output

```plaintext
BV : [1,5,10]
AV : [2,3,7]
BNV : [4,9,12]
ANV : [6,8,11]
NA : [13]
