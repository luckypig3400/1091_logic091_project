//��Dev C++ �sĶ�X�Ӫ�exe�����ɤ~�i�H���`��ܤ���r
#include <stdio.h>
#include <string.h>

int main()
{

    char name[5][64];
    char phone[5][64];
    char inputCache[64];
    char continueInput[3];

    for (int i = 0; i < 5; i++) //��l�Ʀr���}�C(�M��)
    {
        for (int j = 0; j < 64; j++)
        {
            name[i][j] = '\0';
            phone[i][j] = '\0';
            inputCache[j] = '\0';
        }
    }

    // ���]�ŧiname[3][6]�h:
    // 0 1 2 3 4 5
    // �� �� �� �� �� �� name[0][]
    // �� �� �� �� �� �� name[1][]
    // �� �� �� �� �� �� name[2][]

    // �� �� �� �� �� �� inputCache
    // gets()����r�� �i�H���J���r����s��r���}�C��(�]�t�ť�)

    // �ϥ�strcpy(name[0],inputCache)
    // �i�H��inputCache�r��(�Ϊ̻��OinputCache���C�Ӧr��) �ƻs�� name[0]

    int inputCount = 0;

    while (inputCount < 5)
    { //���i�W�L�r���}�C�d��
        printf("�п�J�m�W�G");
        gets(inputCache);
        strcpy(name[inputCount], inputCache); //�ƻsstring

        printf("�п�J�q�ܡG");
        gets(inputCache);
        strcpy(phone[inputCount], inputCache); //�ƻsstring

        for (int i = 0; i < 5; i++)
    	{
        	if (name[i][0] != '\0')//�p�G���Ӧr�����O�Ū��h��X
        	{
            	printf("%s\t%s\n", name[i], phone[i]);
	        }
    	}

        printf("�O�_�~���J(y/n):");
        gets(continueInput);
        if (continueInput[0] == 'n' || continueInput[0] == 'N')
            break;
        // else do nothing(�q�{�~���J)
        printf("===========================\n");

        inputCount++;
    }

    return 0;
}
