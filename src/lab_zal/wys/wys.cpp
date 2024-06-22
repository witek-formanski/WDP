#include "wys.h"

#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>

int n, k, g;
class State;
class Question;
std::unordered_map<int, State*> States;
std::unordered_set<int> UltimateStates;
int AllExcluded;
int* BitMasks;
std::queue<Question*> QuestionsQueue;
std::queue<State*> StatesQueue;

void generateBitMasks() {
	BitMasks = new int[n];
	int bit = 1;
	for (int i = 0; i < n; i++) {
		BitMasks[i] = bit;
		bit *= k + 2;
	}
}

void generateUltimateStates() {
	AllExcluded = static_cast<int>(pow(k + 2, n)) - 1;
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= k + 1; j++)
			UltimateStates.insert(AllExcluded - j * BitMasks[i]);
}

bool isUltimate(int state) {
	return UltimateStates.count(state);
}

bool isValid(int state) {
	return state < AllExcluded;
}

bool isVisited(int state) {
	return States.count(state);
}

int answerNo(int question, int state) {
	for (int i = question; i >= 0; i--)
		if ((state / BitMasks[i]) % (k + 2) < k + 1)
			state += BitMasks[i];

	return state;
}

int answerYes(int question, int state) {
	for (int i = n - 1; i >= question + 1; i--)
		if ((state / BitMasks[i]) % (k + 2) < k + 1)
			state += BitMasks[i];

	return state;
}

class Question {
public:
	int question;
	int stateYes;
	int stateNo;
	State* yes = nullptr;
	State* no = nullptr;

	Question(int q, int stateYes, int stateNo);
	void AskQuestion();
	int GetMaxStepsToWin();
};

Question::Question(int q, int yep, int nah) : question(q), stateYes(yep), stateNo(nah) {}

class State {
public:
	Question* questionToAsk = nullptr;
	int stepsToWin = 2137;
	int state;
	bool visited = false;
	std::vector<Question*> questionsDown;

	State(int s);
	~State();
	int GetMinStepsToWin();
};

State::State(int s) : state(s) {
	States[state] = this;
	if (!isUltimate(state)) {
		for (int i = 0; i < n - 1; i++) {
			int stateYes = answerYes(i, state);
			if (stateYes == state || !isValid(stateYes))
				continue;
			int stateNo = answerNo(i, state);
			if (stateNo == state || !isValid(stateNo))
				continue;
			questionsDown.push_back(new Question(i, stateYes, stateNo));
			QuestionsQueue.push(questionsDown.back());
		}
	}
}

State::~State() {
	delete questionToAsk;
	for (Question* q : questionsDown) {
		delete q;
	}
}

int State::GetMinStepsToWin() {
	if (visited)
		return stepsToWin;

	int stepsPerQuestion;
	for (Question* question : questionsDown) {
		stepsPerQuestion = question->GetMaxStepsToWin();
		if (stepsPerQuestion < stepsToWin) {
			stepsToWin = stepsPerQuestion;
			questionToAsk = question;
		}
	}
	++stepsToWin;
	visited = true;
	return stepsToWin;
}

void Question::AskQuestion() {
	yes = isVisited(stateYes) ? States[stateYes] : new State(stateYes);
	no = isVisited(stateNo) ? States[stateNo] : new State(stateNo);
}

int Question::GetMaxStepsToWin() {
	if (yes == nullptr && no == nullptr)
		return -420;
	if (yes == nullptr)
		return no->GetMinStepsToWin();
	if (no == nullptr)
		return yes->GetMinStepsToWin();

	return std::max(yes->GetMinStepsToWin(), no->GetMinStepsToWin());
}

void init() {
	States[0] = new State(0);
}

void buildGameTree() {
	init();
	while (!QuestionsQueue.empty()) {
		QuestionsQueue.front()->AskQuestion();
		QuestionsQueue.pop();
	}
}

void createGamePaths() {
	for (int ultimateState : UltimateStates) {
		States[ultimateState]->stepsToWin = 0;
		States[ultimateState]->visited = true;
	}
	States[0]->GetMinStepsToWin();
}

void setup() {
	dajParametry(n, k, g);
	generateBitMasks();
	generateUltimateStates();
	buildGameTree();
	createGamePaths();
}

int parseAnswer(int state) {
	int position = AllExcluded - state;
	for (int i = 0; i < n; i++)
		if (position / BitMasks[n - 1 - i] >= 1)
			return n - i;

	return -1;
}

void askAlice() {
	State* currentState = States[0];
	while (currentState->stepsToWin > 0) {
		currentState = mniejszaNiz(currentState->questionToAsk->question + 2)
			? States[answerYes(currentState->questionToAsk->question, currentState->state)]
			: States[answerNo(currentState->questionToAsk->question, currentState->state)];
	}
	odpowiedz(parseAnswer(currentState->state));
}

void play() {
	while (g--)
		askAlice();
}

void cleanup() {
	for (std::pair<int, State*> state : States)
		delete state.second;
}

int main() {
	setup();
	play();
	cleanup();
}