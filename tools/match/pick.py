import sys
# pick.py SRC IDX DST : write block IDX of SRC to DST
b = open(sys.argv[1]).read().split('// @@')
open(sys.argv[3], 'w').write('// @@' + b[int(sys.argv[2]) + 1])
