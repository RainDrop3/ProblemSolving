/*
 * struct로 각 학생 정보 저장
 * 벡터 저장이 맞을듯? 인덱스 접근 필요하니까
 * GRAD 우선순위 : k이상의 지원자, 지원자수, 코테합
 * 같은 GRAD내 학생 우선순위 : 코테점수, UID
 * map을 원소로 하는 array? -> grad별 구분과 학생 수 파악을 위해.
 *-----------------------
 * 각 grad를 array에 담아둠. -> grad의 cnt가능. -> grad별 vector<pair<int, int>> 생성
 * 걍 이중벡터 쓰기?
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
using namespace std;

struct Student{
    int UID;
    int score;
    Student(int id, int sc):UID(id), score(sc) {}
};

struct GradInfo {
    string name;
    int stu_cnt;
    int sum;
    GradInfo(string s, int c, int su)
        :name(s), stu_cnt(c), sum(su) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, k, num1, num2, ptr = 0;
    string mystr;
    map<string, vector<Student>> grad;
    vector<GradInfo> canu;
    vector<Student> pop_list;
    unordered_set<int> uid_to_remove;

    cin >> N >> k;
    while (N--) {
        cin >> mystr >> num1 >> num2;
        if (mystr == "POP") {
            canu.clear();
            pop_list.clear();
            for (auto& p : grad) {
                //각 grad의 학생을 성적순 정렬
                sort(p.second.begin(), p.second.end(), [](Student& a, Student& b) {
                    if (a.score == b.score) return a.UID > b.UID;
                    return a.score > b.score;
                });
                //모든 grad중 canu 선별
                if (p.second.size() >= k) {
                    int sum = 0;
                    for (auto& stu : p.second) sum += stu.score;
                    canu.emplace_back(p.first, p.second.size(), sum);
                }
            }
            //각 canu들을 학생수 기준 정렬
            sort(canu.begin(), canu.end(), [](GradInfo& a, GradInfo& b) {
                if (a.stu_cnt == b.stu_cnt) return a.sum > b.sum;
                return a.stu_cnt > b.stu_cnt;
            });

            //입력된 범위에 맞는 학생 선별
            ptr = 1;
            if (canu.empty()) continue;
            for (int i=0; i<canu[0].stu_cnt; ++i) {
                for (int j=0; j<canu.size(); ++j) {
                    if (i >= grad[canu[j].name].size()) continue; //인덱스 검사
                    if (ptr >= num1 && ptr <= num2) pop_list.push_back(grad[canu[j].name][i]);
                    ptr++;
                }
                if (ptr > num2) break;
            }


            //선발된 인원 출력 및 삭제
            if (!pop_list.empty()) {
                for (int i=0; i<pop_list.size(); ++i) cout << pop_list[i].UID << " ";
                cout << '\n';

                for (auto& stu : pop_list) uid_to_remove.insert(stu.UID);
                for (auto& p : grad) {
                    auto& stu_v = p.second;
                    stu_v.erase(remove_if(stu_v.begin(), stu_v.end(), [&](Student& s) {
                            return uid_to_remove.count(s.UID);
                        }), stu_v.end());
                }
                uid_to_remove.clear();
            }
        }
        //학생 정보 입력
        else grad[mystr].emplace_back(num1, num2);
    }
}