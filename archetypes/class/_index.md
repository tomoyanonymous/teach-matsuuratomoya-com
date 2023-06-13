---
title: 第N週
date: {{.Date}}
weight: 1
params: 
    pdf_path: "hoge.pdf"
draft: true
---

# {{.Date|  dateFormat "2006"}}年　授業名 第N回

## スライド

{{< embed_pdf >}}

{{< button href=.Page.Params.pdf_path >}}スライド（PDF）{{< /button >}}

{{< button href="slides">}}スライド（HTML）{{< /button >}}
