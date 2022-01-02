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
		n, k = map(int, case.input_data().decode("utf-8").strip().split(' '))
		interactor.writeln(n)
		cnt = 64
		last = -10**18
		#self.comment = str(n)+" "+str(k)
		try:
			while True:
				op = interactor.readtoken(delim=None).decode("utf-8")
				v = interactor.readint(lo=1, hi=n, delim=None)
				if op == '=':
					if v == k:
						self.comment += "Used "+str(64-cnt)+" queries"
						return True
					else:
						self.comment += "Wrong Answer"
						return False
				elif op == '?':
					if cnt == 0:
						self.comment += "Query Limit Exceeded"
						return False
					cnt -= 1
					interactor.writeln(1 if abs(last-v) >= k else 0)
					last = v
				else:
					self.comment += "Invalid Output"
					return False
		except Exception:
			self.comment += "Invalid Output"
			return False
