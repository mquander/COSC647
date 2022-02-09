//'Hello World' netfilter hooks example
//For any packet, we drop it, and log fact to /var/log/syslog
#define __KERNEL__
#define MODULE

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>

static struct nf_hook_ops nfho; //struct holding set of hook function options

//function to be called by hook
unsigned int hook_func(
  void *priv,
  struct sk_buff *skb,
  const struct nf_hook_state *state
) {
  // Write the log to /var/log/syslog
  printk(KERN_INFO "dropAllPackets.c -- hook_func() dropped all packets\n");

  /////////////////////  
  // Drop ALL packets
  /////////////////////
  return NF_DROP;
}

// Called when module loaded using 'insmod'
// Command $ (sudo insmod dropPackets.ko)
int init_module() {
  // Function to call when conditions below met
  nfho.hook = hook_func;

  // Called right after packet recieved, first hook  
  nfho.hooknum = NF_INET_PRE_ROUTING;

  // IPV4 packets
  nfho.pf = PF_INET;

  // Set to highest priority over other hook functions
  nfho.priority = NF_IP_PRI_FIRST;

  //////////////////
  // Register hook
  //////////////////
  nf_register_hook(&nfho);

  // Print to kernel log /var/log/syslog
  printk(KERN_INFO "dropAllPacket.c -- init_module() called\n");

  //return 0 for success
  return 0;
}

// Called when module unloaded using 'rmmod'
// Command $ (sudo rmmod dropPackets.ko)
void cleanup_module() {
  printk(KERN_INFO "dropAllPacket.c -- cleanup_module() called\n");

  //////////////////////////////
  // Cleanup – unregister hook
  //////////////////////////////
  nf_unregister_hook(&nfho);
}
