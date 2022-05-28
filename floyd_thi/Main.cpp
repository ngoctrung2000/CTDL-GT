#include "Header.h"
extern int maTran[MAX][MAX];
extern int D[MAX][MAX];
extern int P[MAX][MAX];
extern int soNut;
int main()
{
	int i, j, x, y, chon, ts;
	int dinh;
	soNut = 0;
	do {
		cout << "\n1. Tao do thi moi";
		cout << "\n2. Xoa mot nut";
		cout << "\n3. Them mot cung";
		cout << "\n4. Tim cung";
		cout << "\n5. Bac cua mot dinh ra";
		cout << "\n6. Tim duong di ngan nhat";
		cout << "\n7. Xem ma tran";
		cout << "\n8. Duyet do thi va Xem cac canh co trong do thi";
		cout << "\n0.Thoat";
		cout << "\nChon chuc nang ban can: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "\nDo thi moi co bap nhieu nut?: ";
			cin >> soNut;
			init();

			x = y = 0;
			while (true)
			{
				cout << "\nNhap x,y lon hon " << soNut << "de thoat" << endl;
				cout << "\nNhap nut dau x= "; cin >> x;
				cout << "\nNhap nut dau y= "; cin >> y;
				if (x < soNut && y < soNut)
				{
					cout << "\nTrong so cua cung: (" << x << "," << y << ")=";
					cin >> ts;
					themCung(x, y, ts);
				}
				else
					break;
			}
			ghiMaTran();
			break;
		case 2:
			cout << "\nXoa mot nut da co trong do thi: ";
			if (soNut < MAX)
			{
				docMaTran();
				--soNut;
				cout << "\nSo nut hien tai= " << soNut;
				ghiMaTran();
			}
			else
				cout << "\nKhong the xoa";
			break;
		case 3:
			docMaTran();
			cout << "\nNhap cung can them x= "; cin >> x;
			cout << "\nNhap cung can them y= "; cin >> y;
			if (x > soNut && y > soNut)
				cout << "\nKhong hop le";
			else
			{
				cout << "\nTrong so cua cung (" << x << "," << y << ")=";
				cin >> ts;
				maTran[x][y] = ts;
			}
			ghiMaTran();
			break;
		case 4:
			docMaTran();
			cout << "\nNhap cung x can tim"; cin >> x;
			cout << "\nNhap cung y can tim"; cin >> y;
			if (x > soNut && y > soNut)
				cout << "\nKhong hop le";
			else
				if (maTran[x][y] > 0)
					cout << "\nCo cung(" << x << "," << y << ")" << "voi trong so" << maTran[x][y];
			break;
		case 5:
			docMaTran();
			cout << "\nBac mot dinh co cung ra: ";
			cout << "\nNhap dinh can biet: "; cin >> dinh;
			cout << "\nBac cua dinh" << dinh << "=" << bacDinhRa(dinh);
			break;
		case 6:
			docMaTran();
			cout << "\nNhap nut di x= "; cin >> x;
			cout << "\nNhap nut den y= "; cin >> y;
			if (x >= soNut || y >= soNut)
				cout << "\nKhong hop le";
			else
			{
				floyd();
				cout << "Chieu dai ngan nhat tu" << x << "den" << y << "la" << D[x][y];
				cout << "\nLo trinh duong di: ";
				inLoTrinh(x, y);
			}
			break;
		case 7:
			cout << "\nXem ma tran";
			docMaTran();
			xemMaTran();
			break;
		case 8:
			docMaTran();
			cout << "\nCac cung co tren do thi la: " << endl;
			for (int i = 0; i <= soNut; i++)
				for (int j = 0; j <= soNut; j++)
					if (maTran[i][j] > 0)
						cout << i << "->" << j << "(" << maTran[i][j] << ")" << endl;
			break;
		}
	} while (chon != 0);
}