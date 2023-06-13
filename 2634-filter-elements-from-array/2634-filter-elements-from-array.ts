function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    const b = arr.filter(fn);
    return b;
};