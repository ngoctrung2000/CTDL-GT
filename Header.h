#pragma once
#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
#define MAX 50
#define VOCUNG 3000
#define FALSE 0
#define TRUE 1
void init();
void xoaCung(int node1, int node2);
void themCung(int node1, int node2, int ts);
void floyd();
void inLoTrinh(int x, int y);
int bacDinhRa(int dinh);
void docMaTran();
void ghiMaTran();
void xemMaTran();