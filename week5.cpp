
>> 
→ READ

<<
→ WRITE

ifstream
→ I = Input

ofstream
→ O = Output

while (in >> x)
→ READ FIRST, THEN ENTER LOOP

eof()
→ End Of File

fail()
→ read/conversion FAILED

bad()
→ BAD / serious error

clear()
→ CLEAR the error flag

ignore()
→ IGNORE / throw away characters

ios::app
→ APPEND
最核心的四句话
1. while (in >> value) > while (!in.eof())

2. clear() 清状态，不删字符

3. ignore() 删字符，不清状态

4. 成功读取一个 value ≠ 整个 record 合法
