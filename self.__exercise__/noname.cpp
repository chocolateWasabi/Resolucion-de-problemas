// ***** git과 github에 대한 좋은 경험 03-12 *****
// 
// 이번 상반기에 다시 코딩 공부를 시작하며 레포를 하나 만들었다.
// 1주일 넘게 1일 1커밋을 성공하고 있는데, 오늘 github을 보니 내가 contribute한 게 하나도 없는 거로 나오더라.
// 그래서 가만 보니 내 github 계정인 y0s30b이 아닌, local 자격 증명인 Yoseob으로 계속 commit이 되고 있었음.
// 이걸 어떻게 할지 찾아보던 도중, 두 가지 사실을 발견했다.
//
// 1. git config --global user.name과 user.email로 자격 증명 설정
// 관련 https://goodtogreate.tistory.com/entry/Git-config-%EC%84%A4%EC%A0%95-%EA%B3%84%EC%A0%95%EC%84%A4%EC%A0%95
//
// 2. 지금까지 잘 못 commit 한 내용에 대해 author 수정을 rebase 라는 방법을 통해 하는 것.
// 관련 https://madplay.github.io/post/change-git-author-name
//
//
// 이렇게 해서 자격 증명 설정하고 rebase를 했는데, branch를 새로 만들지 않고 그냥 --force로 push를 해 버렸더니, 지금까지 commit 한 게 날짜별 정리는 되는데 github repository에 comment를 남긴 것들이 모두 사라지는 문제가 발생...
//
// 매우 멘탈이 나간 상태로 밥을 먹다가 다시 복구하는 방법 발견.
//
// https://americanopeople.tistory.com/206
// git reflog origin master로 보니까 예전 (rebase 하기 전) commit이 전부 살아 있었다.
//
//
// reset 해서 돌아갔더니 github repo에서도 다시 내가 남겼던 comment를 볼 수 있었다 !
//
// 좋은 경험들. git 명령어를 익혀가는 과정 중 좋은 경험 하나 한 것이라고 생각하자.
//
// 이 글 부터 y0s30b 자격 증명으로 commit이 될 것이다 ! (이전 Yoseob은 냅두자.) END