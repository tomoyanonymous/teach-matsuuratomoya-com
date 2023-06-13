---
title: Week N
date: {{.Date}}
weight: 1
params: 
    pdf_path: "hoge.pdf"
draft: true
---

# {{.Date|  dateFormat "2006"}} Class Name / Week N

## Slides

{{< embed_pdf >}}

{{< button href=.Page.Params.pdf_path >}}Slides（PDF）{{< /button >}}

{{< button href="slides">}}Slides（HTML）{{< /button >}}
