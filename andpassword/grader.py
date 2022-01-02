from dmoj.graders.interactive import InteractiveGrader
from dmoj.result import Result, CheckerResult

class Grader(InteractiveGrader):
	comment = ""
	def grade(self, case):
		result = super(Grader, self).grade(case)
		result.points = 0
		if result.result_flag == Result.AC:
			result.points = case.points
		result.feedback = self.comment
		return result

	def interact(self, case, interactor):
		self.comment = ""
		ans = list(map(int, case.input_data().decode("utf-8").split(' ')))
		n = len(ans)
		interactor.writeln(n)
		limit = 5120
		guesses = 0
		while True:
			op = interactor.readtoken(delim=None).decode("utf-8")
			if op == '!':
				arr = list()
				try:
					for i in range(n):
						arr.append(interactor.readint(lo=1, hi=n, delim=None))
				except Exception:
					self.comment = "Invalid Output"
					return False
					
				if arr == ans:
					self.comment = 'Used '+str(guesses)+' Queries'
					return True
				else:
					interactor.writeln(-1)
					self.comment = 'Wrong Answer'
					return False
			elif op == '?':
				guesses += 1
				if guesses > limit:
					self.comment = 'Query Limit Exceeded'
					return False
				try:
					a = interactor.readint(lo=1, hi=n, delim=None)
					b = interactor.readint(lo=1, hi=n, delim=None)
				except Exception:
					self.comment = "Invalid Output"
					return False
					
				if a == b:
					interactor.writeln(-1)
					self.comment = "Invalid Output"
					return False
				res = ans[a-1]&ans[b-1]
				interactor.writeln(res)
			else:
				interactor.writeln(-1)
				self.comment = "Invalid Output"
				return False
