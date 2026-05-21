/* 
  파일이름: main.c
  작 성 자: 윤정빈
  하 는 일: V3.0
*/

#include <stdio.h>

// 전역 변수
// 1. 사용자 정보
char studentInitial = ' ';
int studentID = 0;
int isInfoEntered = 0; // 입력 확인용

// 2. 성적 입력
float GPA = 0.0f;

// 3. 졸업 기준 (학교 규정 / 컴퓨터공학과 기준)
int TotalCredit= 134;
int CommonCredit = 17;
int CoreCredit = 12;
int BasicCredit = 15;
int GeneralCredit = 10;
int MajorCredit = 70;

// 4. 현재 상태 (이수한 학점)
int myCommonCredit = 0;
int myCoreCredit = 0;
int myBasicCredit = 0;
int myGeneralCredit = 0;
int myMajorCredit = 0;

// 함수 선언
void printMenu();
void inputInfo();
void calcGPA();
void runSimulation();
void printData();
void printFinalSummary();

int main() 
{

  // 배열 사용 -> 효율적 데이터 관리 (예정)
/*
  // 5. 계산 결과
  int takenTotalCredit = 0; // 총 이수 학점
  int remainCommonCredit = 0;
  int remainCoreCredit = 0;
  int remainBasicCredit = 0;
  int remainGeneralCredit = 0;
  int remainMajorCredit = 0; // 남은 교양, 전공 학점
  int remainTotalCredit = 0; // 남은 총 이수 학점
*/

  int choice = 0;
  int isRunning = 1;
  int i;

  while(isRunning == 1)
  {
    printMenu();
    printf("메뉴 선택: ");
    scanf("%d", &choice);

    switch(choice)
    {
      case 1:
        inputInfo();
        break;
      case 2:
        calcGPA();
        break;
      case 3:
        runSimulation();
        break;
      case 4:
        printData();
        break;
      case 5:
        printFinalSummary();
        break;
      case 6:
        printf("프로그램을 종료합니다. \n");
        isRunning = 0;
        break;
      default:
        printf("잘못된 입력입니다. 다시 입력하세요. \n");
        break;
    }
  }

  return 0;
}

// 함수 구현

// 메뉴 출력
void printMenu()
{
  printf("=====================================================\n");
  printf("\t[대학 졸업 학점 관리 시스템 V2.0]\n");
  printf("=====================================================\n");
  printf("1. 학생 기본 정보 및 이수 내역 입력\n");
  printf("2. 과목별 성적 입력 및 평균 학점 계산기\n");
  printf("3. 졸업 학점 시뮬레이션\n");
  printf("4. 학생 데이터 조회\n");
  printf("5. 최종 요약 출력\n");
  printf("6. 프로그램 종료\n");
  printf("=====================================================\n");
}

// 1) 정보 입력
void inputInfo()
{
  printf("\n [학생 정보 입력]\n");

  printf("당신의 이니셜과 학번을 입력하세요. (ex. Y 60251822) \n >> ");
  scanf(" %c %d", &studentInitial, &studentID);

  printf("현재 평균 학점(GPA)을 입력하세요. (ex. 3.5) \n >> ");
  scanf("%f", &GPA);

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

  isInfoEntered = 1;
  printf("입력 완료\n");
}

// 2) 평균 학점 계산 (p/np 추가)
void calcGPA()
{
  int numSubjects;
  int tempCredit, totalTempCredit = 0;
  float tempGrade = 0.1f, totalTempPoints = 0.0f;
  char gradeLetter, gradeModifier;
  int i;

  printf("\n[평균 학점 계산]\n");
  printf("과목 수 입력: ");
  scanf("%d", &numSubjects);

  // 배열(예정)

  for(i = 1; i <= numSubjects; i++)
  {
    printf("%d번째 과목 (학점, 등급): ", i);
          scanf("%d %c%c", &tempCredit, &gradeLetter, &gradeModifier);

          // 성적 계산 로직 함수로 분리

          switch(gradeLetter) 
          {
            case 'A':
              if (gradeModifier == '+')
              {
                tempGrade = 4.5f;
              }
              else
              {
                tempGrade =4.0f;
              }
              break;

            case 'B':
              if (gradeModifier == '+')
              {
                tempGrade = 3.5f;
              }
              else
              {
                tempGrade =3.0f;
              }
              break;
          
            case 'C':
              if (gradeModifier == '+')
              {
                tempGrade = 2.5f;
              }
              else
              {
                tempGrade =2.0f;
              }
              break;
          
            case 'D':
              if (gradeModifier == '+')
              {
                tempGrade = 1.5f;
              }
              else
              {
                tempGrade =1.0f;
              }
              break;
          
            case 'F':
              tempGrade = 0.0f;
              break;
          
            default:
              printf("잘못된 등급 -> 'F'처리 \n");
              tempGrade = 0.0f;
              break;
          }
        }
          totalTempCredit += tempCredit;
          totalTempPoints += tempCredit * tempGrade;

        if (totalTempCredit > 0)
        {
          GPA = totalTempPoints / totalTempCredit;
          printf("평균 GPA: %.2f\n", GPA);
        }
        else
        {
          printf("입력 없음\n");
        }
        break;
      }
}

/*
  for (i = 0; isRunning == 1; i++) {

    switch(choice) 
    {
      case 2:
      {
        int numSubjects;
        int tempCredit, totalTempCredit = 0;
        float tempGrade = 0.1f, totalTempPoints = 0.0f;
        char gradeLetter, gradeModifier;

        printf("\n[평균 학점 계산]\n");

        printf("과목 수 입력: ");
        scanf("%d", &numSubjects);

        // 배열(예정)

        for(i = 1; i <= numSubjects; i++)
        {
          printf("%d번째 과목 (학점, 등급): ", i);
          scanf("%d %c%c", &tempCredit, &gradeLetter, &gradeModifier);

          // 성적 계산 로직 함수로 분리

          switch(gradeLetter) 
          {
            case 'A':
              if (gradeModifier == '+')
              {
                tempGrade = 4.5f;
              }
              else
              {
                tempGrade =4.0f;
              }
              break;

            case 'B':
              if (gradeModifier == '+')
              {
                tempGrade = 3.5f;
              }
              else
              {
                tempGrade =3.0f;
              }
              break;
          
            case 'C':
              if (gradeModifier == '+')
              {
                tempGrade = 2.5f;
              }
              else
              {
                tempGrade =2.0f;
              }
              break;
          
            case 'D':
              if (gradeModifier == '+')
              {
                tempGrade = 1.5f;
              }
              else
              {
                tempGrade =1.0f;
              }
              break;
          
            case 'F':
              tempGrade = 0.0f;
              break;
          
            default:
              printf("잘못된 등급 -> 'F'처리 \n");
              tempGrade = 0.0f;
              break;
          }
        }
          totalTempCredit += tempCredit;
          totalTempPoints += tempCredit * tempGrade;

        if (totalTempCredit > 0)
        {
          GPA = totalTempPoints / totalTempCredit;
          printf("평균 GPA: %.2f\n", GPA);
        }
        else
        {
          printf("입력 없음\n");
        }
        break;
      }

      case 3:
        printf("\n[졸업 시뮬레이션]\n");

        if(isInfoEntered == 0)
        {
          printf("먼저 1번 실행\n");
          break;
        }

        // 계산 로직 함수로 분리 (예정)

        // 총 이수 학점 계산
        takenTotalCredit = myMajorCredit + myCommonCredit + myCoreCredit + myBasicCredit;

        // 남은 학점 계산
        remainMajorCredit = MajorCredit - myMajorCredit;
        remainCommonCredit = CommonCredit - myCommonCredit;
        remainCoreCredit = CoreCredit - myCoreCredit;
        remainBasicCredit = BasicCredit - myBasicCredit;
        remainGeneralCredit = GeneralCredit - myGeneralCredit;

        // 조건문 -> 함수로 축약 (예정)

        if(remainMajorCredit < 0)
        {
          remainMajorCredit = 0;
        }
      
        if(remainCommonCredit < 0)
        {
          remainCommonCredit = 0;
        }
      
        if(remainCoreCredit < 0)
        {
          remainCoreCredit = 0;
        }

        if(remainBasicCredit < 0)
        {
          remainBasicCredit = 0;
        }
      
        if(remainGeneralCredit < 0)
        {
          remainGeneralCredit = 0;
        }
      
        if(remainTotalCredit < 0)
        {
          remainTotalCredit = 0;
        }

        if(remainTotalCredit == 0 &&
           remainMajorCredit == 0 &&
           remainCommonCredit == 0 &&
           remainCoreCredit == 0 &&
           remainBasicCredit == 0 &&
           remainGeneralCredit == 0)
        {
          if(GPA > 0.0f)
          {
            printf("졸업 가능\n");
          }
          else
          {
            printf("GPA 부족으로 졸업 불가\n");
          }
        }
        else
        {
          printf("학점 부족으로 졸업 불가\n");

          if(remainMajorCredit > 0)
          {
            printf("전공 학점 부족: %d\n", remainMajorCredit);
          }

          if(remainCommonCredit > 0)
          {
            printf("공통 교양 학점 부족: %d\n", remainCommonCredit);
          }

          if(remainCoreCredit > 0)
          {
            printf("핵심 교양 학점 부족: %d\n", remainCoreCredit);
          }

          if(remainBasicCredit > 0)
          {
            printf("학문 기초 교양 학점 부족: %d\n", remainBasicCredit);
          }

          if(remainTotalCredit > 0)
          {
            printf("전 학점 부족: %d\n", remainTotalCredit);
          }
        }    
        break;
        
      case 4:
        printf("\n[데이터 조회]\n");

        if(isInfoEntered)
        {
          printf("%c(%d)\n", studentInitial, studentID);
        }
        else
        {
          printf("데이터 없음\n");
        }

        break;
        
      case 5:
        printf("\n[최종 요약]\n");

        if(isInfoEntered == 0)
        {
          printf("정보 입력 필요\n");
          break;
        }

        takenTotalCredit = myMajorCredit + myCommonCredit + myCoreCredit + myBasicCredit + myGeneralCredit;

        printf("GPA: %.2f\n", GPA);
        printf("총 학점: %d / %d\n", takenTotalCredit, TotalCredit);
      
        // 출력 함수로 분리 (예정)

        break;
        
      case 6:
        printf("프로그램 종료\n");
        isRunning = 0;
        break;
        
      default:
        printf("잘못된 입력\n");
        break;
    }
  }
  return 0;
*/