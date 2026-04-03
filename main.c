/* 
  파일이름: main.c
  작 성 자: 윤정빈
  하 는 일: V1.0
*/

#include <stdio.h>

int main() {
  // 1. 사용자 정보
  char studentInitial = ' ';
  int studentID = 0;

  // 2. 성적 입력
  float GPA = 0;

  // 3. 졸업 기준 (학교 규정)
  int TotalCredit= 134;
  int CommonCredit = 17;
  int CoreCredit = 12;
  int BasicCredit = 15;
  int GeneralCredit = 10;
  int MajorCredit = 70;

  // 4. 현재 상태 (이수한 학점)
  int myCommonCredit = 0;
  int myCoreCredit = 0;
  int mtBasicCredit = 0;
  int myGeneralCredit = 0;
  int mtMajorCredit = 0;

  // 5. 계산 결과
  int takenTotalCredit = 0; // 총 이수 학점
  int remainCommonCredit = 0;
  int remainCoreCredit = 0;
  int remainBasicCredit = 0;
  int remainGeneralCredit = 0;
  int remainMajorCredit = 0; // 남은 교양, 전공 학점
  int remainTotalCredit = 0; // 남은 총 이수 학점

  // 입력부
  printf("=====================================================\n");
  printf("\t[대학 졸업 학점 관리 시스템 V1.0]\n"); // \t, \n 제어 문자 사용
  printf("=====================================================\n");

  printf("당신의 이니셜과 학번을 입력하세요. (ex. Y 60251822) \n >> ");
  scanf(" %c %d", &studentInitial, &studentID);

  printf("현재 평균 학점(GPA)을 입력하세요. (ex. 3.5) \n >> ");
  scanf("%f", %GPA);

  printf("지금까지 이수한 영역별 학점을 입력하세요. \n");
  printf("전공 학점: ");
  scanf("%d", &myMajorCredit);
  printf("공통 교양 학점: ");
  scanf("%d", &myCommonCredit);
  printf("핵심 교양 학점: ");
  scanf("%d", &myCoreCredit);
  printf("학문 기초 교양 학점: ");
  scanf("%d", &myBasicCredit);
  printf("일반 교양 학점: ");
  scanf("%d", &myGeneralCredit);
  
  // 연산부
  // 총 이수 학점 계산
  takenTotalCredit = myMajorCredit + myCommonCredit + myCoreCredit + myBasicCredit;

  // 남은 학점 계산
  remainMajorCredit = MajorCredit - myMajorCredit;
  remainCommonCredit = CommonCredit - myCommonCredit;
  remainCoreCredit = CoreCredit - myCoreCredit;
  remainBasicCredit = BasicCredit - myBasicCredit;
  remainGeneralCredit = GeneralCredit - myGeneralCredit;

  // 출력부
  printf("=====================================================\n");
  printf("\t[%c(%d)님의 졸업 이수 가이드]\n", studentInitial, studentID);
  printf("=====================================================\n");

  printf("1. 현재 평균 학점: %.2f\n\n", GPA);

  printf("2. 학점 이수 현황\n");
  printf("-총 이수 학점: %d/%d Credit \n\n", takenTotalCredit, TotalCredit);

  printf("3. 영역별 남은 학점\n");
  printf("-전공: %d Credit\n", remainMajorCredit);
  printf("-공통 교양: %d Credit\n", remainCommonCredit);
  printf("-핵심 교양: %d Credit\n", remainCoreCredit);
  printf("-학문 기초 교양: %d Credit\n", remainBasicCredit);
  printf("-일반 교양: %d Credit\n", remainGeneralCredit);
  printf("=====================================================\n");

  return 0;
}
