#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	//TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode ;
int flag=0;
void bulid(TreeNode* &root,int *pre,int pbeg,int pend,int *in,int ibeg,int iend)
{
	if(pbeg==pend && ibeg==iend && pre[pbeg]!=in[ibeg])
	{
		flag=1;
		return;
	}
	TreeNode* node=new TreeNode(pre[pbeg]);
	root=node;
	if(pbeg==pend&&ibeg==iend)
	{
		return;
	}
	int mid=ibeg-1;
	for(int i=ibeg;i<=iend;i++)
	{
		if(in[i]==pre[pbeg])
		{
			mid=i;
			break;
		}
	}
	if(mid==ibeg-1||pre[pbeg]!=in[mid])
	{
		flag=1;
		return;
	}
	int left_len=mid-ibeg;
	int right_len=iend-mid;
	if(left_len>0)
		bulid(root->left,pre,pbeg+1,pbeg+mid-ibeg,in,ibeg,mid-1);
	if(right_len>0)
		bulid(root->right,pre,pbeg+mid-ibeg+1,pend,in,mid+1,iend);
}
