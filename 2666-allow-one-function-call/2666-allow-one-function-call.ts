type Fn = (...args: any[]) => any

function once(fn: Fn): Fn {
    let flag = false;
  return function (...args) {
      const ans = flag?undefined:fn(...args);
      flag = true;
      return ans;
  };
}

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */