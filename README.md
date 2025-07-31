# [Arcturus](https://en.wikipedia.org/wiki/Arcturus) 


> Fundamental programming challenges to practice and master, such as sorting algorithms and other core problem-solving techniques.
 
## Test 
Update the main function `main.cpp` to call specific program e.g
```
	vector<int> arr = {10, 5, 8, 9, 1, 5, 6, 3, 0, 4};
	unique_ptr<Sort> s = make_unique<Bubble>(arr);
	s->sort();
```

and print the `arr` e.g
```
	for (int val: arr) {
	    cout << val << " ";
	}
	cout << endl;
```

## Compile
```
cd arcturus
make
```

## Execute
```
./arcturus
```