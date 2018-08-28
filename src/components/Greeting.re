let component = ReasonReact.statelessComponent("Greetings");

let make = (~name, _children) => {
  ...component,
  render: _self => <div> {ReasonReact.string("Hello! " ++ name)} </div>,
};
