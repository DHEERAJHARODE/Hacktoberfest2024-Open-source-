#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: servindc
"""

import pandas as pd
from plotly.subplots import make_subplots
import plotly.graph_objects as go

def plotly_df(df, title="", n_cols=4):
    "Plots each column of a dataframe in csv format with plotly"
    n = len(df.columns)
    n_rows = n//n_cols + bool(n%n_cols) # +1 row if n%cols not zero

    fig = make_subplots(rows=n_rows, cols=n_cols,
                        subplot_titles=[name for name in df.columns],
                        shared_yaxes=True,# rows x cols size necessary to use h_spacing
                        specs = [[{} for i in range(n_cols)] for j in range(n_rows)],
                        horizontal_spacing = 0.02, vertical_spacing = 0.03)
    # plot dataframe columns:
    for i in range(n):
        try:
            z = df.iloc[:,i]
            #s, m, a, b = df_slopes.iloc[i,:] # spike, min, ax+b
            #line = z[int(s):int(m)]
            #def f(x): return (a)*x+b
            fig.add_trace(go.Scatter(x=df.index, y=z,
                                     line=dict(color="#0069b9"), ),
                          row=i//n_cols+1, col=i%n_cols+1 )
            # linear fit
            #z = f(line.index)
            #w = line.index
            #fig.add_trace(go.Scatter(x=w, y=z, line=dict(color="#cc0000"), ),
            #            row=i//n_cols+1, col=i%n_cols+1,
            #            )
            
            #fig.add_annotation(dict(x=w[2*len(w)//3], y=z[0],
            #                        text=f"m = {a:.2f}", showarrow=False),
            #                        font = dict(color='#cc0000', size=14),
            #                        row=i//n_cols+1, col=i%n_cols+1,)
        except:
            print(f"ERROR plotly_df_slopes(): while adding trace number {i}")
    fig.update_layout(title_text="<b>"+title+"</b>", showlegend=False,
                    height=350*n_rows, width=350*n_cols, # 5*n_cols, 4*n_rows
                    margin=dict(l=20, r=20, t=80, b=20),
                    ) # yaxis_range=[y_min-100,y_max+100],
    return fig

################################################################################

if __name__ == "__main__":
    import sys
    from argparse import ArgumentParser
    from os import path
    
    script = path.basename(__file__)
    print("")

    usage = ("%(prog)s datafile.csv [-h] [-i] [-o] [-d]")
    description = """
    Plots each column of a csv file using the plotly library.
    The new plot file is saved as an html file."""

    parser = ArgumentParser(description=description, usage=usage)

    parser.add_argument('datafile', type=str,
                        help="Data file (csv format).")
    parser.add_argument('-o', '--out_prefix', default='', metavar='',
                        help="Prefix name for the output files.")
    
    args = parser.parse_args()

    datafile = args.datafile
    out_prefix = args.out_prefix

    if out_prefix == "": out_prefix = datafile[:-4]

    df = pd.read_csv(datafile)
    title = path.basename(datafile)[:-4]
    fig = plotly_df(df, title=title, n_cols=4)

    script = path.basename(__file__)

    # saves figure in html
    new_html = out_prefix+".html"
    fig.write_html(file=new_html, auto_play=False)
    print(f"INFO {script}: New file created - '{new_html}'")

    sys.exit()
