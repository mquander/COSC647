#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/udp.h>

static struct nf_hook_ops nfho;

unsigned int hook_func(
  void *priv,
  struct sk_buff *skb,
  const struct nf_hook_state *state
) {
  
  char url[24];
  struct iphdr    * iph;
    
  if (skb) {
    // Get IP header from the socket buffer
    iph = ip_hdr(skb);
	snprintf(url, 24, "%pI4", &iph->saddr);
	
    if (strncmp(url, "13.226.190.107", 24)  == 0 ||
		strncmp(url, "13.226.190.113", 24)  == 0 ||
		strncmp(url, "52.85.91.32", 24)  == 0 ||
		strncmp(url, "52.85.91.6", 24)  == 0 ||
		strncmp(url, "52.85.91.93", 24)  == 0 ||
		strncmp(url, "52.85.91.129", 24)  == 0) {
      printk(KERN_INFO "Firewall : dropped espn.com\n");         
      return NF_DROP;    
    }
  }    
  return NF_ACCEPT;
}

int init_module() {  
  nfho.hook      = (nf_hookfn *) hook_func;
  nfho.hooknum   = NF_INET_PRE_ROUTING;
  nfho.pf        = PF_INET;
  nfho.priority  = NF_IP_PRI_FIRST;
  
  int result = nf_register_hook(&nfho);
  if (result) {
    printk(KERN_DEBUG "Firewall : Error nf_register_hook !\n");
    return 1;
  }
  
  printk(KERN_DEBUG "Firewall : Module charged.\n");  
  return 0;
}

void cleanup_module() {
  nf_unregister_hook(&nfho);
  printk(KERN_DEBUG "Firewall : Module decharged.\n");
}
