from dmoj.graders.interactive import InteractiveGrader
from dmoj.result import Result, CheckerResult

class Grader(InteractiveGrader):

    guesses = 0
    comment = ""

    def grade(self, case):
        result = super(Grader,self).grade(case)
        result.points = 0
        if result.result_flag == Result.AC:
            if self.guesses <= 1:
                result.points = 100
            elif self.guesses == 2:
                result.points = 75
            elif self.guesses <= 10:
                result.points = 50
            elif self.guesses <= 50:
                result.points = 30
            elif self.guesses <= 110:
                result.points = 20
            else:
                result.points = 10
        if self.comment != "":
            result.feedback = self.comment
        return result

    def interact(self, case, interactor):
        self.guesses = 0
        self.comment = ""

        answer = int(case.input_data().strip())

        while True:
            self.comment = "No Answer"
            user_input = interactor.readln().strip().split()
            self.comment = ""
            if len(user_input) != 2:
                self.comment = "Presentation Error"
                return False
            try:
                guess = int(user_input[1])
            except Exception:
                self.comment = "Presentation Error"
                return False
            if user_input[0] == b"guess":
                if (guess < -50 or guess > 50):
                    self.comment = "Presentation Error"
                    return False
                interactor.writeln(abs(answer-guess))
                self.guesses += 1
            elif user_input[0] == b"answer":
                if guess == answer:
                    return True
                else:
                    self.comment = "Wrong Answer"
                    return False
            else:
                self.comment = "Presentation Error"
                return False

