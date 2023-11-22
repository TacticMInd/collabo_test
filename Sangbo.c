#include <stdio.h>
#include <string.h>

#define MAX_PERSONS 100

// Person 정보를 담을 구조체 정의
struct Person_Rec {
    int id;          // 학번
    char name[10];   // 이름
    char tel[15];    // 전화번호
    int grade;       // 학년
};

// n명의 정보를 구조체 배열에 입력하는 함수
void inputPersons(struct Person_Rec persons[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("학번: ");
        scanf_s("%d", &persons[i].id);
        printf("이름: ");
        scanf_s("%s", persons[i].name);
        printf("전화번호: ");
        scanf_s("%s", persons[i].tel);
        printf("학년: ");
        scanf_s("%d", &persons[i].grade);
    }
}

// 이름 또는 학번을 받아 해당 학생을 검색하여 정보를 반환하는 함수
struct Person_Rec searchPerson(struct Person_Rec persons[], int n, char key[]) {
    struct Person_Rec notFound = { -1, "", "", -1 }; // 찾지 못한 경우를 나타내는 객체

    for (int i = 0; i < n; ++i) {
        if (strcmp(persons[i].name, key) == 0 || persons[i].id == atoi(key)) {
            return persons[i]; // 해당하는 학생을 찾은 경우 정보를 반환
        }
    }

    return notFound; // 찾지 못한 경우
}

// 메인 함수
int main() {
    int n;
    printf("학생 수: ");
    scanf_s("%d", &n);

    struct Person_Rec persons[MAX_PERSONS];

    // 학생 정보 입력
    inputPersons(persons, n);

    char key[20];
    printf("\n학생 검색 (이름 또는 학번): ");
    scanf_s("%s", key);

    // 학생 검색
    struct Person_Rec foundPerson = searchPerson(persons, n, key);

    if (foundPerson.id != -1) {
        printf("\n학생 정보 찾음:\n");
        printf("학번: %d\n이름: %s\n전화번호: %s\n학년: %d\n", foundPerson.id, foundPerson.name, foundPerson.tel, foundPerson.grade);
    }
    else {
        printf("\n학생 정보를 찾지 못했습니다.\n");
    }

    return 0;
}
