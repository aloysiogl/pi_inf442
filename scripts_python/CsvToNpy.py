import numpy as np
import sys


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('Usage: CsvToNpy.py dataName')

    orgpath = '../data/representation.' + sys.argv[1] + '.csv'
    destpath = '../data/representation.' + sys.argv[1] + '-sample.npy'
    data = np.loadtxt(orgpath, delimiter=",")
    np.save(destpath, data)

    orgpath = '../data/true_labels.' + sys.argv[1] + '.csv'
    destpath = '../data/true_labels.' + sys.argv[1] + '-sample.npy'
    data = np.loadtxt(orgpath, dtype=str)
    np.save(destpath, data)