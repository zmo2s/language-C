void Tri_Selection(liste *tete)
{
liste *p, *q, *min;
int aide;
for(p=tete ; p->next!=NULL ; p=p->next)
{
min=p;
for(q=p->next ; q!=NULL ; q=q->next)
{
if(q->val < min->val)
{
min=q;
}
}
aide=p->val;
p->val = min->val;
min->val = aide;
}
}