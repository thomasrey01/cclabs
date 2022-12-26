for ex in {4..4}
do
	rm -rf tests$ex
	mkdir tests$ex

	for t in {1..10}
	do
		curl \
		-H "cookie: acceptedLanguages=nl; usernameType=student; session=s%3AKbwB5I4OVmCtWLs0hFzmlGk-x10ug56t.HxuiVsccb4z0TYCrM%2FmrEi%2FbM%2BljGOr3SbhjatfdMT8"\
		https://themis.housing.rug.nl/file/2021-2022/cs-SS/lab3/ex$ex/@tests/$t.in \
		-o tests$ex/$t.in

		curl \
		-H "cookie: acceptedLanguages=nl; usernameType=student; session=s%3AKbwB5I4OVmCtWLs0hFzmlGk-x10ug56t.HxuiVsccb4z0TYCrM%2FmrEi%2FbM%2BljGOr3SbhjatfdMT8" \
		https://themis.housing.rug.nl/file/2021-2022/cs-SS/lab3/ex$ex/@tests/$t.out \
		-o tests$ex/$t.out
	done
done
