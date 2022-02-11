#include <stdio.h>

int rsbac_acl_sys_group(enum  rsbac_acl_group_syscall_type_t call,
                            union rsbac_acl_group_syscall_arg_t arg){
    ...
        switch(call){
            case ACLGS_get_group_members:
              if((arg.get_group_members.maxnum <= 0) || !arg.get_group_members.group){
		...
                rsbac_uid_t * user_array;
                rsbac_time_t * ttl_array;

                user_array = vmalloc(sizeof(*user_array) *
                arg.get_group_members.maxnum);   /* [B] */
                if(!user_array)
                  return -RSBAC_ENOMEM;
                ttl_array = vmalloc(sizeof(*ttl_array) *
                arg.get_group_members.maxnum); /* [C] */
                if(!ttl_array)
                  {
                    vfree(user_array);
                    return -RSBAC_ENOMEM;
                  }

                err =
                rsbac_acl_get_group_members(arg.get_group_members.group,
                                                  user_array,
                                                  ttl_array,
                                                  arg.get_group_members.max
                                                  num);
    ...
    }
