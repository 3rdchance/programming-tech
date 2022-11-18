# do_set_pte
/* copy-on-write page */
if (write && !(vma->vm_flags & VM_SHARED)) {
        inc_mm_counter_fast(vma->vm_mm, MM_ANONPAGES);
        page_add_new_anon_rmap(page, vma, addr);
        lru_cache_add_inactive_or_unevictable(page, vma);
} else {
        inc_mm_counter_fast(vma->vm_mm, mm_counter_file(page));
        page_add_file_rmap(page, vma, false);
}


  2   1319  fs/dax.c <<dax_fault_cow_page>>
             ret = finish_fault(vmf);
   3   4337  mm/memory.c <<finish_fault>>
             vm_fault_t finish_fault(struct vm_fault *vmf)
   4   4515  mm/memory.c <<do_read_fault>>
             ret |= finish_fault(vmf);
   5   4550  mm/memory.c <<do_cow_fault>>
             ret |= finish_fault(vmf);
   6   4584  mm/memory.c <<do_shared_fault>>
             ret |= finish_fault(vmf);


# dev_dax_fault
return VM_FAULT_NOPAGE

# do_cow_fault
if (unlikely(ret & (VM_FAULT_ERROR | VM_FAULT_NOPAGE | VM_FAULT_RETRY)))               
         goto uncharge_out;
if (ret & VM_FAULT_DONE_COW)
         return ret;
                     
do not call finish_fault
