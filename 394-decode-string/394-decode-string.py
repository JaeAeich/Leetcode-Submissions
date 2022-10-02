class Solution:
    def decodeString(self, s: str) -> str:
        st=[]
        for i in s:
            
            #pushing chars will we reach closing braces.
            if(i !="]"):
                st.append(i)
                
            else:
                #once a closing bracket is reached then start poping
                #       stack till opening bracket is reached.
                temp=""
                while st[len(st)-1]!="[":
                    temp=st.pop()+temp
                st.pop()
                
                #now get the number before opening bracket and multiply string 
                #        with that num.
                val=""
                while st and st[-1].isdigit():
                    val=st.pop()+val
                    
                #push string into stack because this string might be from a nested 
                #         brace and need to be multiplied further.
                st.append(int(val)*temp)
                
        #join all the string in the stack
        return "".join(st)