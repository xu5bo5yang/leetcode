int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int result = (C-A) * (D-B) + (G-E) * (H-F);
    if (A>=G || C<=E || B>=H || D<=F) return result;
    int intersec = ((C<G?C:G) - (A>E?A:E)) * ((D<H?D:H) - (B>F?B:F));
    return result-intersec;
}