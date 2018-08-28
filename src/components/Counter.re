type state = {
  count: int,
  show: bool,
};

type action =
  | Click(option(int))
  | Toggle;

let component = ReasonReact.reducerComponent("Counter");

let make = (~greeting, _children) => {
  ...component,
  initialState: () => {count: 0, show: false},
  reducer: (action, state) =>
    switch (action) {
    | Click(None) => ReasonReact.Update({...state, count: state.count + 1})
    | Click(Some(num)) =>
      ReasonReact.Update({...state, count: state.count + num})
    | Toggle => ReasonReact.Update({...state, show: !state.show})
    },
  render: self => {
    let message =
      "You've clicked this " ++ string_of_int(self.state.count) ++ " times";
    <div>
      <button onClick={_event => self.send(Click(None))}>
        {ReasonReact.string(message)}
      </button>
      <button onClick={_event => self.send(Click(Some(3)))}>
        {ReasonReact.string(message ++ " - add 3")}
      </button>
      <button onClick={_event => self.send(Toggle)}>
        {ReasonReact.string("Toggle greeting")}
      </button>
      {self.state.show ? ReasonReact.string(greeting) : ReasonReact.null}
    </div>;
  },
};
